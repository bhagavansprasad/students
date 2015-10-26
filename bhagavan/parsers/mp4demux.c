#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

#define STATE_INITIAL 0
#define STATE_HEADER  1

#define GaloisMalloc malloc
#define GaloisFree	 free

#define DMX_FILE_LEVEL_PRINT_ENABLE (0x01)
#define ENABLE_FILE_WRITE

#define MP4_MAKE_FOURCC(d,c,b,a)  (a | (b<<8) | (c<<16) | (d<<24))

#define FOURCC_ftyp     MP4_MAKE_FOURCC('f','t','y','p')
#define FOURCC_moov     MP4_MAKE_FOURCC('m','o','o','v')
#define FOURCC_mvhd     MP4_MAKE_FOURCC('m','v','h','d')
#define FOURCC_clip     MP4_MAKE_FOURCC('c','l','i','p')
#define FOURCC_trak     MP4_MAKE_FOURCC('t','r','a','k')
#define FOURCC_udta     MP4_MAKE_FOURCC('u','d','t','a')
#define FOURCC_ctab     MP4_MAKE_FOURCC('c','t','a','b')
#define FOURCC_tkhd     MP4_MAKE_FOURCC('t','k','h','d')
#define FOURCC_vide     MP4_MAKE_FOURCC('v','i','d','e')
#define FOURCC_soun     MP4_MAKE_FOURCC('s','o','u','n')

#define INPUT_FILE_PATH		   "D:\\Mp4Files\\X.mp4"
#define OUTPUT_VIDEO_ES_PATH   "D:\\Mp4Files\\ESOut\\VideoES.h264"
#define OUTPUT_AUDIO_ES_PATH   "D:\\Mp4Files\\ESOut\\AudioES.aac"
#define OUTPUT_VIDEO_PTS_PATH  "D:\\Mp4Files\\ESOut\\VideoPTS.txt"
#define OUTPUT_AUDIO_PTS_PATH  "D:\\Mp4Files\\ESOut\\AudioPTS.txt"

#define MAX_AUDIO_SAMPLE_SIZE_BEFORE_MALLOC  (2*1024)
#define MAX_VIDEO_SAMPLE_SIZE_BEFORE_MALLOC  (512 * 1024)

typedef enum
{
	CONTENT_TYPE_VIDEO = 0,
	CONTENT_TYPE_AUDIO,
	CONTENT_TYPE_MAX
}contenttype_e;

typedef enum
{
	DMX_ERR_OK = 0,
	DMX_ERR_INVALID_PARAM,
	DMX_ERR_NON_SUPPORTED_FORMAT,
	DMX_ERR_NON_SUPPORTED_ENCODING,
	DMX_ERR_FUNC_FAILED,
	DMX_ERR_SRC_READ_FAILED,
	DMX_ERR_MAX
}Errtype_e;

int curr_offset = 0;
int m_count = 2;
int state = 0;
unsigned char *m_MoovBox = NULL;
int m_TimeScale = 0;
static unsigned int m_TotalDuration = 0;

unsigned char *m_FirstTrck = NULL;
unsigned char *m_SecondTrck = NULL;
unsigned char *m_AudTrck = NULL;
unsigned char *m_VidTrck = NULL;

unsigned int m_VideoTrckTotalDuration = 0;
int m_VideoTrckDuration = 0;
unsigned int m_VideoTrckTimeScale = 0;

unsigned char *m_VidStbl = NULL;
unsigned char *m_VidStsc = NULL;
unsigned char *m_VidStsz = NULL;
unsigned char *m_VidStco = NULL;
unsigned char *m_VidStsd = NULL;
unsigned char *m_VidAvcc = NULL;
unsigned char *m_VidStts = NULL;
unsigned char *m_VidStss = NULL;

unsigned char *m_AudStbl = NULL;
unsigned char *m_AudStsc = NULL;
unsigned char *m_AudStsz = NULL;
unsigned char *m_AudStco = NULL;
unsigned char *m_AudStsd = NULL;
unsigned char *m_AudStts = NULL;
int m_TotNumofVideoSamples = 0;
int m_NumofChunks = 0;
int m_VideoSampleDuration = 0;
unsigned int m_AudioTrckTotalDuration = 0;
int m_NumofAudioChunks = 0;
int m_TotNumofAudioSamples = 0;
int m_pAudioVersionNum = 0;
int m_pAudioNumChannels = 0;
int m_pAudiosamplingFreq = 0;
int m_AudioSampleDuration = 0;
int m_lengthByte = 0;
unsigned int m_StsdLength = 0;

int m_NumofAudSttsEntries = 0;
int m_NumofVidSttsEntries = 0;
unsigned int m_AudTrckTimeScale = 0;

FILE *fp = NULL;
FILE *fpAAC = NULL;
FILE *fpH264 = NULL;
FILE *fpVidPTS = NULL;
FILE *fpAudPTS = NULL;

unsigned int totMemoryUsed = 0;

const int AAC_sample_rate_table[16] = {
    96000, 88200, 64000, 48000, 44100, 32000,
    24000, 22050, 16000, 12000, 11025, 8000, 7350,0,0,0
};

Errtype_e getStscData(unsigned char *stblBox,int stblLength);
Errtype_e getStszData(unsigned char *stblBox,int stblLength);
Errtype_e getStcoData(unsigned char *stblBox,int stblLength);
Errtype_e getStsdData(unsigned char *stblBox,int stblLength);
Errtype_e getVideoSttsData(unsigned char *stblBox,int stblLength);
Errtype_e getVideoStssData(unsigned char *stblBox,int stblLength);
Errtype_e getAudioMdhdBox(unsigned char *trckBox,int trcklength);
Errtype_e processAudioTrackNow(unsigned char *trckBox,int trcklength);
Errtype_e processAudioSamplesNow(unsigned char *stblBox,int stblLength);


////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    convertFromBetoLe
//! Description: Given the 32 bit data, it will convert a big endian data to
//!little endian format
//! \param: data: Which holds the darta which need to be converted
//! \return Return: int
/////////////////////////////////////////////////////////////////////////////////
unsigned int convertFromBetoLe(unsigned char *data)
{
   unsigned int num = 0;
   num = ((( data[3]) |( data[2] << 8)|( data[1]<< 16)  |( data[0]<<24)));
   return num;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    convertFromBetoLe16Bit
//! Description: Given the 16 bit data, it will convert a big endian data to
//!              lille endian format
//! \param: data: Which holds the darta which need to be converted
//! \return Return: int
/////////////////////////////////////////////////////////////////////////////////
unsigned int convertFromBetoLe16Bit(unsigned char *data)
{
   unsigned int num = 0;
   num = (( data[1]) |( data[0] << 8));
   return num;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    extract_initial_length_and_fourcc
//! Description: this function will be used to get size of a box
//! \param: buf: data holding the size
//!         length: the size, output param
//!         fourCC: what type of box it is, output param
//! \return Return: void
/////////////////////////////////////////////////////////////////////////////////
Errtype_e extract_initial_length_and_fourcc(unsigned char *buf, unsigned int *length,
                                      unsigned int *fourCC )
{
   if(( NULL == buf ) || ( NULL == length) || (NULL == fourCC))
   {
       return DMX_ERR_INVALID_PARAM;
   }

   *length = convertFromBetoLe(buf);
   *fourCC = convertFromBetoLe(buf+4);
#if DMX_FILE_LEVEL_PRINT_ENABLE
   printf("\nLength is %d and type is 0x%x\n",*length,*fourCC);
#endif
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getTimeScaleData
//! Description: this function will get the duration and the time scale for a mp4
//!              file
//! \param: m_MoovBox: moov box data
//! \return Return: int
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getTimeScaleData(unsigned char *m_MoovBox)
{
   unsigned int ClipDuration = 0;
   unsigned char *tempMoovBox = (m_MoovBox + 8);

   if( NULL == m_MoovBox)
   {
		return DMX_ERR_INVALID_PARAM;
   }

   m_TimeScale = convertFromBetoLe(tempMoovBox + 20);
   ClipDuration = convertFromBetoLe(tempMoovBox + 24);
   /*Now get the duration in terms of seconds*/
   ClipDuration = (ClipDuration/m_TimeScale);
   m_TotalDuration = (ClipDuration * 1000);
   #if DMX_FILE_LEVEL_PRINT_ENABLE
      printf("\nThe time scale for this track is %d,duration is %d,tot duration is %d\n",m_TimeScale,ClipDuration,m_TotalDuration);
   #endif
   return DMX_ERR_OK;
}


////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getMdhdBox
//!
//! Description: This function will get mdhd box for video and fetch total duration
//!              and time scale for the track
//! \param: trckBox: pointer to trckBox box data
//!         trcklength: Length of the buffer
//! \return Return: error code
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getMdhdBox(unsigned char *trckBox,int trcklength )
{
   unsigned char *pTrckBox = trckBox;
   int position = 0;
   int mdHdLength = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};
   int bFound = 0;
   unsigned char *l_mdHd = NULL;
   double totTrackDuration = 0.0;

   if(( NULL == trckBox)||( 0 == trcklength ))
   {
	   return DMX_ERR_INVALID_PARAM;
   }

   /*Now first get mdhd box*/
  while(trcklength--)
  {
   if(*pTrckBox == 'm')
   {
       arr[0] = *pTrckBox;
       arr[1] = *++pTrckBox;
       arr[2] = *++pTrckBox;
       arr[3] = *++pTrckBox;
       if( 0 == strcmp(arr,"mdhd"))
       {
#if DMX_FILE_LEVEL_PRINT_ENABLE
           printf("\nFound mdhd for video\n");
#endif
           bFound = 1;
           break;
       }
       else
       {
           pTrckBox--;
           pTrckBox--;
       }
   }
   else
   {
       pTrckBox++;
   }
 }

 if( 1 == bFound )
 {
   position = (pTrckBox - trckBox - 7);
   mdHdLength = convertFromBetoLe(trckBox + position);

   /*l_mdHd = (unsigned char *)GaloisMalloc((mdHdLength + 1)*sizeof(unsigned char));

   if( NULL == l_mdHd )
   {
   #if DMX_FILE_LEVEL_PRINT_ENABLE
	   printf("\nFailed to allocate memory for mdhd\n");
   #endif
       return DMX_ERR_FUNC_FAILED;
   }
   memset(l_mdHd,'\0',(mdHdLength + 1));
   memcpy(l_mdHd,(trckBox + position),mdHdLength);*/
   l_mdHd = (trckBox + position);

   m_VideoTrckTotalDuration = convertFromBetoLe(l_mdHd + 24);
   m_VideoTrckTimeScale = convertFromBetoLe(l_mdHd + 20);
   totTrackDuration = (double)((double)m_VideoTrckTotalDuration/(double)m_VideoTrckTimeScale);
   //m_VideoTrckTotalDuration = ( m_VideoTrckTotalDuration * 1000 ); //in terms of miliseconds
#if DMX_FILE_LEVEL_PRINT_ENABLE
   printf("\nTotal video duration received here in float for video is %f\n",totTrackDuration);
#endif
   m_VideoTrckTotalDuration = (unsigned int)( totTrackDuration * 1000 ); //in terms of miliseconds
#if DMX_FILE_LEVEL_PRINT_ENABLE
   printf("\nTotal Duration of video track is %d,time scale is %d\n",m_VideoTrckTotalDuration,m_VideoTrckTimeScale);
#endif
   //free(l_mdHd);
 }
 else
 {
	 printf("\nCouldn't find Mdhd box for video\n");
	 return DMX_ERR_FUNC_FAILED;
 }
 return DMX_ERR_OK;
}


contenttype_e determineTrckContenttype(unsigned char *trckBox, int trckLen)
{
	unsigned char *pTrckBox = trckBox;
	int position = trckLen;
	char arr[5] = {'\0','\0','\0','\0','\0'};
	int bfound = 0;
	int trackType = 0;
	contenttype_e contenttype = CONTENT_TYPE_MAX;
	if(( NULL == trckBox )||( 0 == trckLen ))
	{
		return CONTENT_TYPE_MAX;
	}

	while( position-- )
	{
		if(*pTrckBox == 'h')
		{
			arr[0] = *pTrckBox;
			arr[1] = *++pTrckBox;
			arr[2] = *++pTrckBox;
			arr[3] = *++pTrckBox;
			if( 0 == strcmp(arr,"hdlr"))
			{
				printf("\nFound the handler\n");
				bfound = 1;
				break;
			}
			else
			{
				pTrckBox--;
				pTrckBox--;
			}
		}
		else
		{
			pTrckBox++;
		}
	}

	if( bfound == 1)
	{
		pTrckBox = ( pTrckBox - 3);
		trackType = convertFromBetoLe(pTrckBox + 12);
		switch(trackType)
		{
			case FOURCC_vide:
			{
				printf("\nThis is a video track\n");
				contenttype = CONTENT_TYPE_VIDEO;
			}
			break;

			case FOURCC_soun:
			{
				printf("\nThis is an audio track\n");
				contenttype = CONTENT_TYPE_AUDIO;
			}
			break;

			default:
			{
				printf("\nThere is something wrong\n");
				contenttype = CONTENT_TYPE_MAX;
			}
			break;
		}
	}
	return contenttype;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    processSamplesNow
//!
//! Description: This function will get stbl box for video and fetch all the video
//!              sample related information
//! \param: trckBox: pointer to stblBox data
//!         trcklength: Length of the buffer
//! \return Return: error code
/////////////////////////////////////////////////////////////////////////////////
Errtype_e processSamplesNow(unsigned char *stblBox,int stblLength)
{
   if(( NULL == stblBox )||( stblLength < 0))
   {
       return DMX_ERR_INVALID_PARAM;
   }

   if( DMX_ERR_OK == getStscData(stblBox,stblLength))
   {
	   if( DMX_ERR_OK == getStszData(stblBox,stblLength))
	   {
		   if( DMX_ERR_OK == getStcoData(stblBox,stblLength))
		   {
			   if( DMX_ERR_OK == getStsdData(stblBox,stblLength))
			   {
				   if( DMX_ERR_OK == getVideoSttsData(stblBox,stblLength))
				   {
				       if( DMX_ERR_OK == getVideoStssData( stblBox,stblLength))
					   {
					   }
				   }
				   else
				   {
					   return DMX_ERR_FUNC_FAILED;
				   }
			   }
			   else
			   {
				   return DMX_ERR_FUNC_FAILED;
			   }
		   }
		   else
		   {
			   return DMX_ERR_FUNC_FAILED;
		   }
	   }
	   else
	   {
		   return DMX_ERR_FUNC_FAILED;
	   }
   }
   else
   {
	   return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}


////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getStscData
//!
//! Description: This function will get stsc box for a video track
//! \param: stblBox: Stbl box
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getStscData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int stscLength = 0;
   int bfound = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};

   if(( NULL == stblBox )||( 0 == stblLength ))
   {
	   return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
    if(*pStblBox == 's')
    {
        arr[0] = *pStblBox;
        arr[1] = *++pStblBox;
        arr[2] = *++pStblBox;
        arr[3] = *++pStblBox;
        if( 0 == strcmp(arr,"stsc"))
        {
            bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stsc for video\n");
#endif
            break;
        }
        else
        {
            pStblBox--;
            pStblBox--;
        }
    }
    else
    {
        pStblBox++;
    }
   }
   if( 1 == bfound )
   {
       position = (pStblBox - stblBox - 7);
       stscLength = convertFromBetoLe(stblBox + position);
       /*m_VidStsc = (unsigned char *)GaloisMalloc((stscLength + 1)*sizeof(unsigned char));
	   if( NULL == m_VidStsc )
	   {
		   printf("\nFailed to get memory stsc length\n");
		   return DMX_ERR_FUNC_FAILED;
	   }
       memset(m_VidStsc,'\0',(stscLength + 1));
       memcpy(m_VidStsc,(stblBox + position),stscLength);

	   totMemoryUsed += (stscLength + 1);*/
	   m_VidStsc = (stblBox + position);
	   printf("\nThe video stsc length is %d\n",stscLength);
   }
   else
   {
       printf("\nCouldn't find stsc for video\n");
	   return DMX_ERR_FUNC_FAILED;
   }
   m_NumofChunks = convertFromBetoLe(m_VidStsc + 12);
#if DMX_FILE_LEVEL_PRINT_ENABLE
   printf("\nNumber of chunks are %d\n",m_NumofChunks);
#endif
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getStszData
//!
//! Description: This function will get stsz box for a video track
//! \param: stblBox: Stbl box
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getStszData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int stszLength = 0;
   int bfound = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};

   if(( NULL == stblBox )||( 0 == stblLength ))
   {
	   return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
    if(*pStblBox == 's')
    {
        arr[0] = *pStblBox;
        arr[1] = *++pStblBox;
        arr[2] = *++pStblBox;
        arr[3] = *++pStblBox;
        if( 0 == strcmp(arr,"stsz"))
        {
            bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stsz for video\n");
#endif
            break;
        }
        else
        {
            pStblBox--;
            pStblBox--;
        }
    }
    else
    {
        pStblBox++;
    }
   }
   if( 1 == bfound )
   {
       position = (pStblBox - stblBox - 7);
       stszLength = convertFromBetoLe(stblBox + position);
       /*m_VidStsz = (unsigned char *)GaloisMalloc((stszLength + 1)*sizeof(unsigned char));
       if( NULL == m_VidStsz )
	   {
	       printf("\nFailed to get memory stsz length\n");
		   return DMX_ERR_FUNC_FAILED;
	   }
	   memset(m_VidStsz,'\0',(stszLength + 1));
	   memcpy(m_VidStsz,(stblBox + position),stszLength);
	   totMemoryUsed += (stszLength + 1);*/
	   m_VidStsz = (stblBox + position);
	   printf("\nThe video stsz length is %d\n",stszLength);
   }
   else
   {
       printf("\nCouldn't find stsz for video\n");
	   return DMX_ERR_FUNC_FAILED;
   }
   m_TotNumofVideoSamples = convertFromBetoLe(m_VidStsz + 16);
#if DMX_FILE_LEVEL_PRINT_ENABLE
   printf("\nTotal number of video samples are %d\n",m_TotNumofVideoSamples);
#endif
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getStcoData
//!
//! Description: This function will get stco box for a video track
//! \param: stblBox: Stbl box
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getStcoData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int stcoLength = 0;
   int bfound = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};

   if(( NULL == stblBox )||( stblLength <= 0))
   {
	   return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
    if(*pStblBox == 's')
    {
        arr[0] = *pStblBox;
        arr[1] = *++pStblBox;
        arr[2] = *++pStblBox;
        arr[3] = *++pStblBox;
        if( 0 == strcmp(arr,"stco"))
        {
            bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stco for video\n");
#endif
            break;
        }
        else
        {
            pStblBox--;
            pStblBox--;
        }
    }
    else
    {
        pStblBox++;
    }
   }
   if( 1 == bfound )
   {
    position = (pStblBox - stblBox - 7);
    stcoLength = convertFromBetoLe(stblBox + position);
    /*m_VidStco = (unsigned char *)GaloisMalloc((stcoLength + 1)*sizeof(unsigned char));
    if( NULL == m_VidStsz )
    {
        printf("\nFailed to get memory stsc length\n");
        return DMX_ERR_FUNC_FAILED;
    }
    memset(m_VidStco,'\0',(stcoLength + 1));
    memcpy(m_VidStco,(stblBox + position),stcoLength);
	totMemoryUsed += (stcoLength + 1);*/
	m_VidStco = (stblBox + position);
	printf("\nThe video stco length is %d\n",stcoLength);
   }
   else
   {
    printf("\nCouldn't find stco for video\n");
	return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getStsdData
//!
//! Description: This function will get stsd box for a video track
//! \param: stblBox: Stbl box
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getStsdData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int stsdLength = 0;
   int bfound = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};
   unsigned short Height = 0, Width = 0;
   unsigned short Bitrate = 0;

   if(( NULL == stblBox )||( stblLength <= 0))
   {
	   return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
    if(*pStblBox == 's')
    {
        arr[0] = *pStblBox;
        arr[1] = *++pStblBox;
        arr[2] = *++pStblBox;
        arr[3] = *++pStblBox;
        if( 0 == strcmp(arr,"stsd"))
        {
            bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stsd for video\n");
#endif
            break;
        }
        else
        {
            pStblBox--;
            pStblBox--;
        }
    }
    else
    {
        pStblBox++;
    }
   }
   if( 1 == bfound )
   {
    position = (pStblBox - stblBox - 7);
    stsdLength = convertFromBetoLe(stblBox + position);
    /*m_VidStsd = (unsigned char *)GaloisMalloc((stsdLength + 1)*sizeof(unsigned char));
    if( NULL == m_VidStsd )
    {
        printf("\nFailed to get memory stsz length\n");
        return DMX_ERR_FUNC_FAILED;
    }
    memset(m_VidStsd,'\0',(stsdLength + 1));
    memcpy(m_VidStsd,(stblBox + position),stsdLength);
	totMemoryUsed += (stsdLength + 1);*/
	m_VidStsd = (stblBox + position);
    /*Now print height and width of the video*/
    Width = convertFromBetoLe16Bit(m_VidStsd + 48);
    Height = convertFromBetoLe16Bit(m_VidStsd + 50);
    Bitrate = convertFromBetoLe16Bit(m_VidStsd + 98);
    m_StsdLength = stsdLength;
#if DMX_FILE_LEVEL_PRINT_ENABLE
    printf("\nWidth = %d,Height = %d\n",Width,Height);
    printf("\nBitrate = %d\n",Bitrate);
    printf("\nThe video stsd length is %d\n",stsdLength);
#endif
   }
   else
   {
       printf("\nCouldn't find stsz for video\n");
	   return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getVideoSttsData
//!
//! Description: This function will get stts box for a video track
//! \param: stblBox: Stbl box
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getVideoSttsData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int sttsLength = 0;
   int bfound = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};
   unsigned int FrameRate = 0;

   if(( NULL == stblBox )||( stblLength <= 0))
   {
	   return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
    if(*pStblBox == 's')
    {
        arr[0] = *pStblBox;
        arr[1] = *++pStblBox;
        arr[2] = *++pStblBox;
        arr[3] = *++pStblBox;
        if( 0 == strcmp(arr,"stts"))
        {
            bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stts for video\n");
#endif
            break;
        }
        else
        {
            pStblBox--;
            pStblBox--;
        }
    }
    else
    {
        pStblBox++;
    }
   }
   if( 1 == bfound )
   {
    position = (pStblBox - stblBox - 7);
    sttsLength = convertFromBetoLe(stblBox + position);
    /*m_VidStts = (unsigned char *)malloc((sttsLength + 1)*sizeof(unsigned char));
    if( NULL == m_VidStts )
    {
        printf("\nFailed to get memory stss length\n");
        return DMX_ERR_FUNC_FAILED;
    }
    memset(m_VidStts,'\0',(sttsLength + 1));
    memcpy(m_VidStts,(stblBox + position),sttsLength);
	totMemoryUsed += (sttsLength + 1);*/
	m_VidStts = (stblBox + position);
	printf("\nThe video stsd length is %d\n",sttsLength);
   }
   else
   {
    printf("\nCouldn't find stts for video\n");
	return DMX_ERR_FUNC_FAILED;
   }
   if( 1 == convertFromBetoLe(m_VidStts + 12))
   {
    m_VideoSampleDuration = convertFromBetoLe(m_VidStts + 20);
	printf("\nAll samples are of same duration\n");
	m_NumofVidSttsEntries = 0;
   }
   else
   {
	   m_NumofVidSttsEntries = convertFromBetoLe(m_VidStts + 12);
	   printf("\nNumber of entries in video stts table are %d\n",m_NumofVidSttsEntries);
	   m_VideoSampleDuration = 0;
   }
   if( m_VideoSampleDuration > 0 )
   {
    FrameRate = (m_VideoTrckTimeScale/m_VideoSampleDuration);
#if DMX_FILE_LEVEL_PRINT_ENABLE
    printf("\nFrame rate is %d\n",FrameRate);
#endif
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getVideoStssData
//!
//! Description: This function will get stss box for a video track
//! \param: stblBox: Stbl box
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getVideoStssData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int stssLength = 0;
   int bfound = 0;
   int entryCount = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};

   if(( NULL == stblBox )||( stblLength <= 0))
   {
	   return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
   if(*pStblBox == 's')
   {
    arr[0] = *pStblBox;
    arr[1] = *++pStblBox;
    arr[2] = *++pStblBox;
    arr[3] = *++pStblBox;
    if( 0 == strcmp(arr,"stss"))
    {
        bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
        printf("\nFound stss for video\n");
#endif
        break;
    }
    else
    {
        pStblBox--;
        pStblBox--;
    }
   }
   else
   {
    pStblBox++;
   }
   }
   if( 1 == bfound )
   {
   position = (pStblBox - stblBox - 7);
   stssLength = convertFromBetoLe(stblBox + position);
   /*m_VidStss = (unsigned char *)malloc((stssLength + 1)*sizeof(unsigned char));
   if( NULL == m_VidStss )
   {
    printf("\nFailed to get memory stss length\n");
    return DMX_ERR_FUNC_FAILED;
   }
   memset(m_VidStss,'\0',(stssLength + 1));
   memcpy(m_VidStss,(stblBox + position),stssLength);
   totMemoryUsed += (stssLength + 1);*/
   m_VidStss = (stblBox + position);
   entryCount = convertFromBetoLe(m_VidStss + 12);
   printf("\nThe video stss length is %d,number of IDR frames=%d\n",stssLength,entryCount);
   }
   else
   {
     printf("\nCouldn't find stss for video\n");
     return DMX_ERR_OK; /*Here we are returning OK as it is not a mandatory table*/
   }
   return DMX_ERR_OK;
}


////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    processVideoTrackNow
//!
//! Description: This function will parse the track box for video and get the
//!              stbl box
//! \param: trckBox: pointer to moov box data
//!         trcklength: Length of the buffer
//! \return Return: error code
/////////////////////////////////////////////////////////////////////////////////
Errtype_e processVideoTrackNow(unsigned char *trckBox,int trcklength )
{
   unsigned char *pTrckBox = trckBox;
   int position = 0;
   int stblLength = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};
   int bFound = 0;

   if(( NULL == trckBox )||( trcklength <= 0))
   {
	   return DMX_ERR_INVALID_PARAM;
   }
   /*Now first get stbl box*/
   while(trcklength--)
   {
	    if(*pTrckBox == 's')
		{
			arr[0] = *pTrckBox;
			arr[1] = *++pTrckBox;
			arr[2] = *++pTrckBox;
			arr[3] = *++pTrckBox;
			if( 0 == strcmp(arr,"stbl"))
			{
	#if DMX_FILE_LEVEL_PRINT_ENABLE
				printf("\nFound stbl for video\n");
	#endif
				bFound = 1;
				break;
			}
			else
			{
				pTrckBox--;
				pTrckBox--;
			}
		}
		else
		{
			pTrckBox++;
		}
   }

   if( 1 == bFound )
   {
    position = (pTrckBox - trckBox - 7);
    stblLength = convertFromBetoLe(trckBox + position);

    /*m_VidStbl = (unsigned char *)GaloisMalloc((stblLength + 1)*sizeof(unsigned char));
    if( NULL == m_VidStbl )
    {
        printf("\nFailed to get memory stbl length\n");
        return DMX_ERR_FUNC_FAILED;
    }
    memset(m_VidStbl,'\0',(stblLength + 1));
    memcpy(m_VidStbl,(trckBox + position),stblLength);*/
    m_VidStbl = (trckBox + position);
    if( DMX_ERR_OK != processSamplesNow(m_VidStbl,stblLength))
    {
		return DMX_ERR_FUNC_FAILED;
	}
	else
	{
		//GaloisFree(m_VidStbl);
		m_VidStbl = NULL;
	}
   }
   else
   {
      printf("\nDidn't find stbl for video\n");
      return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getTrckBox
//!
//! Description: This function will get track box for audio
//! \param: moovBox: Pointer to moov box data
//!         moovLength: length of moov box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getTrckBox(unsigned char *moovBox, int moovLength)
{
   unsigned char *pMoovBox = moovBox;
   char arr[5] = {'\0','\0','\0','\0','\0'};
   int position = moovLength;
   int secondTrackPosition = 0;
   int secondtrckLength = 0;
   contenttype_e contentType = CONTENT_TYPE_MAX;

	if(( NULL == m_MoovBox )||( moovLength <= 0))
	{
		printf("\nWromg input params\n");
		return DMX_ERR_INVALID_PARAM;
	}

    while( position-- )
    {
        if(*pMoovBox == 't')
        {
			arr[0] = *pMoovBox;
			arr[1] = *++pMoovBox;
			arr[2] = *++pMoovBox;
			arr[3] = *++pMoovBox;
			if( 0 == strcmp(arr,"trak"))
			{
	#if DMX_FILE_LEVEL_PRINT_ENABLE
				printf("\nFound one trak\n");
	#endif
				break;
			}
			else
			{
				pMoovBox--;
				pMoovBox--;
				//pMoovBox--;
			}
		}
		else
		{
			pMoovBox++;
		}
   }
   #if DMX_FILE_LEVEL_PRINT_ENABLE
       printf("\nThe offset at which the second track found is %d\n",(pMoovBox - moovBox));
   #endif
   secondTrackPosition = ( pMoovBox - moovBox - 7); //7 came from ( 4 + 3), 3 is for trak string and 4 is it's size
   secondtrckLength = convertFromBetoLe(moovBox + secondTrackPosition );
   /*m_FirstTrck = (unsigned char *)GaloisMalloc( (secondtrckLength+1) * sizeof(unsigned char));
   if( NULL == m_FirstTrck )
   {
	   printf("\nFailed to allocate memory for the track pointer\n");
	   return DMX_ERR_FUNC_FAILED;
   }
   memset(m_FirstTrck,'\0',(secondtrckLength+1));
   memcpy(m_FirstTrck,(moovBox + secondTrackPosition),secondtrckLength);*/
   m_FirstTrck = (moovBox + secondTrackPosition);
   /*Determine whether this track is audio or video*/
   contentType = determineTrckContenttype(m_FirstTrck,secondtrckLength);
   if( CONTENT_TYPE_VIDEO == contentType )
   {
	   m_VidTrck = m_FirstTrck;
	   getMdhdBox(m_VidTrck,secondtrckLength);
	   if( DMX_ERR_OK != processVideoTrackNow(m_VidTrck,secondtrckLength))
	   {
		   return DMX_ERR_FUNC_FAILED;
	   }
	   else
	   {
		   //GaloisFree(m_VidTrck);
		   m_VidTrck = NULL;
	   }
   }
   else if( CONTENT_TYPE_AUDIO == contentType )
   {
	   m_AudTrck = m_FirstTrck;
	   getAudioMdhdBox(m_AudTrck,secondtrckLength);
	   if( DMX_ERR_OK != processAudioTrackNow(m_AudTrck,secondtrckLength))
	   {
		   return DMX_ERR_FUNC_FAILED;
	   }
	   else
	   {
		   //GaloisFree(m_AudTrck);
		   m_AudTrck = NULL;
	   }
   }
   else
   {
	   return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getAudioMdhdBox
//!
//! Description: This function will get mdhd box for audio
//! \param: trckBox: Pointer to track box data
//!         trcklength: length of track box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getAudioMdhdBox(unsigned char *trckBox,int trcklength )
{
   unsigned char *pTrckBox = trckBox;
   int position = 0;
   int mdHdLength = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};
   int bFound = 0;
   unsigned char *l_mdHd = NULL;
   unsigned int l_AudTrckTimeScale = 0;
   float totTrackDuration = 0.0;

   if(( NULL == trckBox )||( trcklength <= 0 ))
   {
	   return DMX_ERR_INVALID_PARAM;
   }

   /*Now first get mdhd box*/
   while(trcklength--)
   {
       if(*pTrckBox == 'm')
       {
           arr[0] = *pTrckBox;
           arr[1] = *++pTrckBox;
           arr[2] = *++pTrckBox;
           arr[3] = *++pTrckBox;
           if( 0 == strcmp(arr,"mdhd"))
           {
#if DMX_FILE_LEVEL_PRINT_ENABLE
               printf("\nFound mdhd for audio\n");
#endif
               bFound = 1;
               break;
           }
           else
           {
               pTrckBox--;
               pTrckBox--;
           }
       }
       else
       {
           pTrckBox++;
       }
   }

   if( 1 == bFound )
   {
       position = (pTrckBox - trckBox - 7);
       mdHdLength = convertFromBetoLe(trckBox + position);

       /*l_mdHd = (unsigned char *)GaloisMalloc((mdHdLength + 1)*sizeof(unsigned char));

       if( NULL == l_mdHd )
       {
           printf("\nFailed to allocate memory for mdhd\n");
           return DMX_ERR_FUNC_FAILED;
       }
       memset(l_mdHd,'\0',(mdHdLength + 1));
       memcpy(l_mdHd,(trckBox + position),mdHdLength);*/
       l_mdHd = (trckBox + position);

       m_AudioTrckTotalDuration = convertFromBetoLe(l_mdHd + 24);
       l_AudTrckTimeScale = convertFromBetoLe(l_mdHd + 20);
       totTrackDuration = (float)((float)(m_AudioTrckTotalDuration)/(float)(l_AudTrckTimeScale));
#if DMX_FILE_LEVEL_PRINT_ENABLE
       printf("\nAudio track duration in float received here is %f\n",totTrackDuration);
#endif
       m_AudioTrckTotalDuration = (unsigned)( totTrackDuration * 1000 ); //In terms of miliseconds
#if DMX_FILE_LEVEL_PRINT_ENABLE
       printf("\nTotal Audio trck Duration is %d,sampling rate is %d\n",m_AudioTrckTotalDuration,l_AudTrckTimeScale);
#endif
	   m_AudTrckTimeScale = l_AudTrckTimeScale;
	   //free(l_mdHd);
   }
   else
   {
	   printf("\nCouldn't find mdhd box fr audio\n");
	   return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}


////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    processAudioTrackNow
//!
//! Description: This function will process audio track box and get stbl box
//!              for audio
//! \param: trckBox: Pointer to track box data
//!         trcklength: length of track box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e processAudioTrackNow(unsigned char *trckBox,int trcklength )
{
   unsigned char *pTrckBox = trckBox;
   int position = 0;
   int stblLength = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};
   int bFound = 0;

   if(( NULL == trckBox )||( trcklength <= 0 ))
   {
       return DMX_ERR_INVALID_PARAM;
   }

   /*Now first get stbl box*/
   while(trcklength--)
   {
    if(*pTrckBox == 's')
    {
        arr[0] = *pTrckBox;
        arr[1] = *++pTrckBox;
        arr[2] = *++pTrckBox;
        arr[3] = *++pTrckBox;
        if( 0 == strcmp(arr,"stbl"))
        {
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stbl for audio\n");
#endif
            bFound = 1;
            break;
        }
        else
        {
            pTrckBox--;
            pTrckBox--;
        }
    }
    else
    {
        pTrckBox++;
    }
   }
   if( 1 == bFound )
   {
    position = (pTrckBox - trckBox - 7);
    stblLength = convertFromBetoLe(trckBox + position);

    /*m_AudStbl = (unsigned char *)GaloisMalloc((stblLength + 1)*sizeof(unsigned char));
    if( NULL == m_AudStbl )
    {
        printf("\nFailed to get memory stbl length\n");
        return DMX_ERR_FUNC_FAILED;
    }
    memset(m_AudStbl,'\0',(stblLength + 1));
    memcpy(m_AudStbl,(trckBox + position),stblLength);*/
    m_AudStbl = (trckBox + position);
    if( DMX_ERR_OK != processAudioSamplesNow(m_AudStbl,stblLength))
    {
		return DMX_ERR_FUNC_FAILED;
	}
	else
	{
		//GaloisFree(m_AudStbl);
		m_AudStbl = NULL;
	}
   }
   else
   {
       printf("\nDidn't find stbl for audio\n");
       return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getAudioStscData
//! Description: This function will get stsc box data for audio track
//! \param: stblBox: Stbl box data
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getAudioStscData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int stscLength = 0;
   int bfound = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};

   if(( NULL == stblBox )||( stblLength <= 0 ))
   {
	   return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
    if(*pStblBox == 's')
    {
        arr[0] = *pStblBox;
        arr[1] = *++pStblBox;
        arr[2] = *++pStblBox;
        arr[3] = *++pStblBox;
        if( 0 == strcmp(arr,"stsc"))
        {
            bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stsc for audio\n");
#endif
            break;
        }
        else
        {
            pStblBox--;
            pStblBox--;
        }
    }
    else
    {
        pStblBox++;
    }
   }
   if( 1 == bfound )
   {
    position = (pStblBox - stblBox - 7);
    stscLength = convertFromBetoLe(stblBox + position);
    /*m_AudStsc = (unsigned char *)GaloisMalloc((stscLength + 1)*sizeof(unsigned char));
    totMemoryUsed += (stscLength + 1);
    if( NULL == m_AudStsc )
    {
        printf("\nFailed to get memory stsc length\n");
        return DMX_ERR_FUNC_FAILED;
    }
    memset(m_AudStsc,'\0',(stscLength + 1));
    memcpy(m_AudStsc,(stblBox + position),stscLength);*/
    m_AudStsc = (stblBox + position);
    printf("\nThe audio stsc length is %d\n",stscLength);
   }
   else
   {
       printf("\nCouldn't find stsc for audio\n");
       return DMX_ERR_FUNC_FAILED;
   }
   m_NumofAudioChunks = convertFromBetoLe(m_AudStsc + 12);
#if DMX_FILE_LEVEL_PRINT_ENABLE
   printf("\nNumber of chunks are %d\n",m_NumofAudioChunks);
#endif
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getAudioStszData
//! Description: This function will get stsz box data for audio track
//! \param: stblBox: Stbl box data
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getAudioStszData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int stszLength = 0;
   int bfound = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};

   if(( NULL == stblBox )||( stblLength <= 0 ))
   {
   	   return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
    if(*pStblBox == 's')
    {
        arr[0] = *pStblBox;
        arr[1] = *++pStblBox;
        arr[2] = *++pStblBox;
        arr[3] = *++pStblBox;
        if( 0 == strcmp(arr,"stsz"))
        {
            bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stsz for audio\n");
#endif
            break;
        }
        else
        {
            pStblBox--;
            pStblBox--;
        }
    }
    else
    {
        pStblBox++;
    }
   }
   if( 1 == bfound )
   {
    position = (pStblBox - stblBox - 7);
    stszLength = convertFromBetoLe(stblBox + position);
    /*m_AudStsz = (unsigned char *)GaloisMalloc((stszLength + 1)*sizeof(unsigned char));
    totMemoryUsed += (stszLength + 1);
    if( NULL == m_AudStsz )
    {
        printf("\nFailed to get memory stsz length\n");
        return DMX_ERR_FUNC_FAILED;
    }
    memset(m_AudStsz,'\0',(stszLength + 1));
    memcpy(m_AudStsz,(stblBox + position),stszLength);*/
    m_AudStsz = (stblBox + position);
    printf("\nThe audio stsz length is %d\n",stszLength);
   }
   else
   {
       printf("\nCouldn't find stsz for audio\n");
       return DMX_ERR_FUNC_FAILED;
   }
   m_TotNumofAudioSamples = convertFromBetoLe(m_AudStsz + 16);
#if DMX_FILE_LEVEL_PRINT_ENABLE
   printf("\nTotal number of AUDIO samples are %d\n",m_TotNumofAudioSamples);
#endif
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getAudioStcoData
//! Description: This function will get stco box data for audio track
//! \param: stblBox: Stbl box data
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getAudioStcoData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int stcoLength = 0;
   int bfound = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};

   if(( NULL == stblBox )||( stblLength <= 0 ))
   {
       return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
    if(*pStblBox == 's')
    {
        arr[0] = *pStblBox;
        arr[1] = *++pStblBox;
        arr[2] = *++pStblBox;
        arr[3] = *++pStblBox;
        if( 0 == strcmp(arr,"stco"))
        {
            bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stco for audio\n");
#endif
            break;
        }
        else
        {
            pStblBox--;
            pStblBox--;
        }
    }
    else
    {
        pStblBox++;
    }
   }
   if( 1 == bfound )
   {
    position = (pStblBox - stblBox - 7);
    stcoLength = convertFromBetoLe(stblBox + position);
    /*m_AudStco = (unsigned char *)GaloisMalloc((stcoLength + 1)*sizeof(unsigned char));
    totMemoryUsed += (stcoLength + 1);
    if( NULL == m_AudStco )
    {
        printf("\nFailed to get memory stsc length\n");
        return DMX_ERR_FUNC_FAILED;
    }
    memset(m_AudStco,'\0',(stcoLength + 1));
    memcpy(m_AudStco,(stblBox + position),stcoLength);*/
    m_AudStco = (stblBox + position);
    printf("\nThe audio stco length is %d\n",stcoLength);
   }
   else
   {
       printf("\nCouldn't find stco for audio\n");
       return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getSamplingIndex
//! Description: this function will get frequency index based on the sampling
//!              frequency
//! \param: SamplingFreq: frequency
//! \return Return: int
/////////////////////////////////////////////////////////////////////////////////
unsigned int getSamplingIndex(int SamplingFreq)
{
   int count = 0;
   for( count = 0; count < 16; count++)
   {
    if(AAC_sample_rate_table[count] == SamplingFreq)
    {
        break;
    }
   }
   if(16 == count)
   {
    count = 4;
   }
   return count;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getAudioStsdData
//! Description: This function will get stsd box data for audio track
//! \param: stblBox: Stbl box data
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getAudioStsdData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int stsdLength = 0;
   int bfound = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};

   if(( NULL == stblBox )||( stblLength <= 0 ))
   {
       return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
    if(*pStblBox == 's')
    {
        arr[0] = *pStblBox;
        arr[1] = *++pStblBox;
        arr[2] = *++pStblBox;
        arr[3] = *++pStblBox;
        if( 0 == strcmp(arr,"stsd"))
        {
            bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stsd for audio\n");
#endif
            break;
        }
        else
        {
            pStblBox--;
            pStblBox--;
        }
    }
    else
    {
        pStblBox++;
    }
   }
   if( 1 == bfound )
   {
    position = (pStblBox - stblBox - 7);
    stsdLength = convertFromBetoLe(stblBox + position);
    /*m_AudStsd = (unsigned char *)GaloisMalloc((stsdLength + 1)*sizeof(unsigned char));
    totMemoryUsed += (stsdLength + 1);
    if( NULL == m_AudStsd )
    {
        printf("\nFailed to get memory stsz length\n");
        return DMX_ERR_FUNC_FAILED;
    }
    memset(m_AudStsd,'\0',(stsdLength + 1));
    memcpy(m_AudStsd,(stblBox + position),stsdLength);*/
    m_AudStsd = (stblBox + position);

    /*Now get the chanell related and other informations*/
   m_pAudioVersionNum = convertFromBetoLe(m_AudStsd + 32);
   m_pAudioNumChannels = convertFromBetoLe16Bit(m_AudStsd + 40);
   m_pAudiosamplingFreq = getSamplingIndex(convertFromBetoLe16Bit(m_AudStsd + 48));
   printf("\nThe audio stsd length is %d\n",stsdLength);
   }
   else
   {
       printf("\nCouldn't find stsz for audio\n");
       return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getAudioSttsData
//! Description: This function will get stts box data for audio track
//! \param: stblBox: Stbl box data
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getAudioSttsData(unsigned char *stblBox,int stblLength)
{
   unsigned char *pStblBox = stblBox;
   int position = 0;
   int sttsLength = 0;
   int bfound = 0;
   char arr[5] = {'\0','\0','\0','\0','\0'};

   if(( NULL == stblBox )||( stblLength <= 0 ))
   {
       return DMX_ERR_INVALID_PARAM;
   }

   while(stblLength--)
   {
    if(*pStblBox == 's')
    {
        arr[0] = *pStblBox;
        arr[1] = *++pStblBox;
        arr[2] = *++pStblBox;
        arr[3] = *++pStblBox;
        if( 0 == strcmp(arr,"stts"))
        {
            bfound = 1;
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound stts for audio\n");
#endif
            break;
        }
        else
        {
            pStblBox--;
            pStblBox--;
        }
    }
    else
    {
        pStblBox++;
    }
   }
   if( 1 == bfound )
   {
    position = (pStblBox - stblBox - 7);
    sttsLength = convertFromBetoLe(stblBox + position);
    /*m_AudStts = (unsigned char *)malloc((sttsLength + 1)*sizeof(unsigned char));
    totMemoryUsed += (sttsLength + 1);
    if( NULL == m_AudStts )
    {
        printf("\nFailed to get memory stts length\n");
        return DMX_ERR_FUNC_FAILED;
    }
    memset(m_AudStts,'\0',(sttsLength + 1));
    memcpy(m_AudStts,(stblBox + position),sttsLength);*/
    m_AudStts = (stblBox + position);
    printf("\nThe audio stts length is %d\n",sttsLength);
   }
   else
   {
       printf("\nCouldn't find stts for audio\n");
       return DMX_ERR_FUNC_FAILED;
   }
   if( 1 == convertFromBetoLe(m_AudStts + 12))
   {
    m_AudioSampleDuration = convertFromBetoLe(m_AudStts + 20);
	printf("\nAll audio samples are of same stamp\n,duratio is %d\n",m_AudioSampleDuration);
	m_NumofAudSttsEntries = 0;
   }
   else
   {
	   m_AudioSampleDuration = 0;
	   m_NumofAudSttsEntries = convertFromBetoLe(m_AudStts+12);
	   printf("\nEach one of them has one,tot num of stts entries=%d\n",m_NumofAudSttsEntries);
   }
   return DMX_ERR_OK;
}


////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    processAudioTrackNow
//!
//! Description: This function will process all the sample related tables and get
//!              the required information
//! \param: stblBox: Pointer to stbl box data
//!         stblLength: length of stbl box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e processAudioSamplesNow(unsigned char *stblBox,int stblLength)
{
   if(( NULL == stblBox )||( stblLength <= 0 ))
   {
       return DMX_ERR_INVALID_PARAM;
   }

   if( DMX_ERR_OK != getAudioStscData(stblBox,stblLength))
   {
       return DMX_ERR_FUNC_FAILED;
   }

   if( DMX_ERR_OK != getAudioStszData(stblBox,stblLength))
   {
	   return DMX_ERR_FUNC_FAILED;
   }

   if( DMX_ERR_OK != getAudioStcoData(stblBox,stblLength))
   {
       return DMX_ERR_FUNC_FAILED;
   }

   if( DMX_ERR_OK != getAudioStsdData(stblBox,stblLength))
   {
       return DMX_ERR_FUNC_FAILED;
   }

   if( DMX_ERR_OK != getAudioSttsData(stblBox,stblLength))
   {
       return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getAnotherTrckBox
//!
//! Description: This function will get track box for the next track
//! \param: moovBox: Pointer to moov box data
//!         moovLength: length of moov box
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e getAnotherTrckBox(unsigned char *moovBox, int moovLength)
{
   unsigned char *pMoovBox = moovBox;
   char arr[5] = {'\0','\0','\0','\0','\0'};
   int count = 0;
   int position = moovLength;
   int secondTrackPosition = 0;
   int secondtrckLength = 0;
   contenttype_e contentType = CONTENT_TYPE_MAX;
   if(( NULL == m_MoovBox )||( 0 == moovLength))
   {
		printf("\nWromg input params\n");
		return DMX_ERR_INVALID_PARAM;
   }

   /*try to find the trck*/
   while( position-- )
   {
    if(*pMoovBox == 't')
    {
        arr[0] = *pMoovBox;
        arr[1] = *++pMoovBox;
        arr[2] = *++pMoovBox;
        arr[3] = *++pMoovBox;
        if( 0 == strcmp(arr,"trak"))
        {
#if DMX_FILE_LEVEL_PRINT_ENABLE
            printf("\nFound one trak\n");
#endif
            count++;
            if( count >= 2)
            {
#if DMX_FILE_LEVEL_PRINT_ENABLE
                printf("\nFound the second trak\n");
#endif
                break;
            }
        }
        else
        {
            pMoovBox--;
            pMoovBox--;
            //pMoovBox--;
        }
    }
    else
    {
        pMoovBox++;
    }
   }
#if DMX_FILE_LEVEL_PRINT_ENABLE
   printf("\nThe offset at which the second track found is %d\n",(pMoovBox - moovBox));
#endif
   secondTrackPosition = ( pMoovBox - moovBox - 7); //7 came from ( 4 + 3), 3 is for trak string and 4 is it's size
   secondtrckLength = convertFromBetoLe(moovBox + secondTrackPosition );
   /*m_SecondTrck = (unsigned char *)GaloisMalloc( (secondtrckLength+1) * sizeof(unsigned char));
   if( NULL == m_SecondTrck )
   {
	   printf("\nFailed to allocate memory for the track pointer\n");
	   return DMX_ERR_FUNC_FAILED;
   }
   memset(m_SecondTrck,'\0',(secondtrckLength+1));
   memcpy(m_SecondTrck,(moovBox + secondTrackPosition),secondtrckLength);*/
   m_SecondTrck = (moovBox + secondTrackPosition);
   /*Determine whether this track is audio or video*/
   contentType = determineTrckContenttype(m_SecondTrck,secondtrckLength);
   if( CONTENT_TYPE_VIDEO == contentType )
   {
	   m_VidTrck = m_SecondTrck;
	   if( DMX_ERR_OK != getMdhdBox(m_VidTrck,secondtrckLength))
	   {
		   return DMX_ERR_FUNC_FAILED;
	   }
	   if( DMX_ERR_OK != processVideoTrackNow(m_VidTrck,secondtrckLength))
	   {
		   return DMX_ERR_FUNC_FAILED;
	   }
	   else
	   {
		   //GaloisFree(m_VidTrck);
		   m_VidTrck = NULL;
	   }
   }
   else if( CONTENT_TYPE_AUDIO == contentType )
   {
	   m_AudTrck = m_SecondTrck;
	   if( DMX_ERR_OK != getAudioMdhdBox(m_AudTrck,secondtrckLength))
	   {
		   return DMX_ERR_FUNC_FAILED;
	   }
	   if( DMX_ERR_OK != processAudioTrackNow(m_AudTrck,secondtrckLength))
	   {
		   return DMX_ERR_FUNC_FAILED;
	   }
	   else
	   {
		   //GaloisFree(m_AudTrck);
		   m_AudTrck = NULL;
	   }
   }
   else
   {
	   return DMX_ERR_FUNC_FAILED;
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    parseMoovBox
//!
//! Description: test function for parsing moov box
//! \param: fp: file pointer from where data will be read
//!         length: length of moov box
//!         currentpos: current file position
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
Errtype_e parseMoovBox( FILE *fp,int length, int currentpos )
{
	int numberoBytesRead = 0;
	printf("\nWe are in parseMoovBox,length=%d\n",length);
	if( NULL == m_MoovBox )
    {
        printf("\nnot enough memory for moov box\n");
        return DMX_ERR_FUNC_FAILED;
    }
	if( DMX_ERR_OK != getTimeScaleData(m_MoovBox))
	{
		return DMX_ERR_FUNC_FAILED;
	}
	if( DMX_ERR_OK != getTrckBox(m_MoovBox,length))
	{
		return DMX_ERR_FUNC_FAILED;
	}
	printf("\n++++++Get another track+++\n");
	if( DMX_ERR_OK != getAnotherTrckBox(m_MoovBox,length))
	{
		return DMX_ERR_FUNC_FAILED;
	}
	return 0;
}

Errtype_e parseMp4Header(FILE *fp)
{
   int readBytes = 0;
   unsigned char destBuf[20] = "\0";
   unsigned int length = 0;
   unsigned int fourCC= 0;
   unsigned char *readBuff = NULL;
   int currentPos = 0;

	if( NULL == fp )
	{
		return DMX_ERR_INVALID_PARAM;
	}

	readBytes = fread(destBuf,sizeof(unsigned char),16,fp);

   if( 16 == readBytes )
   {
       if( DMX_ERR_OK != extract_initial_length_and_fourcc(destBuf,&length,&fourCC))
	   {
		   printf("\nFailed in extract_initial_length_and_fourcc\n");
		   return DMX_ERR_FUNC_FAILED;
	   }
   }

   switch (fourCC)
   {
	    case FOURCC_ftyp:
		{
			readBuff = (unsigned char *)GaloisMalloc(length * sizeof(unsigned char));
			if(NULL == readBuff )
			{
				printf("\nFailed in malloc for FOURCC_ftyp\n");
				return DMX_ERR_SRC_READ_FAILED;
			}
			readBytes = fread(readBuff,sizeof(unsigned char),(length - 16),fp);
			curr_offset = length;
		}
        break;

		case FOURCC_moov:
		{
		#if DMX_FILE_LEVEL_PRINT_ENABLE
				printf("\nIn moov box\n");
		#endif
				m_MoovBox = (unsigned char *)GaloisMalloc((length + 1)* sizeof(unsigned char));
				if(NULL == m_MoovBox )
				{
					printf("\nFailed in malloc for FOURCC_moov\n");
					return DMX_ERR_FUNC_FAILED;
				}
				totMemoryUsed += (length + 1);
				fseek(fp,curr_offset,SEEK_SET);
				currentPos = ftell(fp);
		#if DMX_FILE_LEVEL_PRINT_ENABLE
				printf("\nCurrent pos after ftell is %d\n",currentPos);
		#endif
				readBytes = fread(m_MoovBox,sizeof(unsigned char),length,fp);
				if( DMX_ERR_OK != parseMoovBox(fp,length,currentPos))
				{
					return DMX_ERR_FUNC_FAILED;
				}
				curr_offset += length;
				m_count = 0;
		}
		break;
   }

   if( NULL != readBuff )
   {
    GaloisFree(readBuff);
    readBuff = NULL;
   }
   return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    Size
//! Description: Gievn an audio sample, this function will get the size of it
//! \param: SampleNum: Sample for which offset is sought
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
int Size(int SampleNum)
{
   int fixedSize = 0;
   int size = 0;
   fixedSize = convertFromBetoLe(m_AudStsz+12);
   if( 0 == fixedSize )
   {
      size = convertFromBetoLe(m_AudStsz+16+(SampleNum*4));
   }
   else
   {
      size = fixedSize;
   }
   return size;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getOffset
//! Description: Gievn an audio sample, this function will get the offset of it
//!              from the start of file
//! \param: SampleNumber: Sample for which offset is sought
//! \return Return: offset
/////////////////////////////////////////////////////////////////////////////////
int getOffset(int SampleNumber)
{
   int counter = 0;
   unsigned int nSampleBase = 0;
   unsigned int nChunkThis = 0;
   int nSamplesPerChunk = 1;
   int nChunkNext = 0,nSampleBaseNext = 0;
   unsigned int nChunkOffset = 0,nSampleOffset = 0;
   unsigned int nByteOffset = 0;
   unsigned int ChunkStart = 0;
   unsigned int totNumofChunks  = 0;
   //for(counter = 1; counter <= m_NumofChunks; counter++)
   if( m_NumofAudioChunks > 1 )
   {
      for(counter = 0; counter < m_NumofAudioChunks; counter++)
      {
    nChunkThis = convertFromBetoLe(m_AudStsc + 4 + (12 * counter)) - 1;
    nSamplesPerChunk = convertFromBetoLe(m_AudStsc + 4 + (12 * counter) + 4);
    nChunkNext = convertFromBetoLe(m_AudStsc + 4 + (12 * (counter + 1))) - 1;
    nSampleBaseNext = nSampleBase + (nChunkNext - nChunkThis)*nSamplesPerChunk;
    //numofSamples += convertFromBetoLe(m_VidStsc + 8 + (12 * counter));
    if((SampleNumber < nSampleBaseNext) ||(counter == (m_NumofAudioChunks-1)))
    {
        break;
    }
    //if( numofSamples == 0 )
    {
        nSampleBase = nSampleBaseNext;
    }
      }
   }
   else
   {
       for(counter = 0; counter < m_NumofAudioChunks; counter++)
    {
        nChunkThis = convertFromBetoLe(m_AudStsc + 16 + (12 * counter)) - 1;
        nSamplesPerChunk = convertFromBetoLe(m_AudStsc + 16 + (12 * counter) + 4);
        nSampleBase = ((SampleNumber/nSamplesPerChunk)*nSamplesPerChunk);
        nChunkNext = 1;
        nSampleBaseNext = nSampleBase + (nChunkNext - nChunkThis)*nSamplesPerChunk;
        //numofSamples += convertFromBetoLe(m_VidStsc + 8 + (12 * counter));
        if(SampleNumber < nSampleBaseNext)
        {
            break;
        }
        //if( numofSamples == 0 )
        {
            nSampleBase = nSampleBaseNext;
        }
    }
   }

    if( m_NumofAudioChunks == 1 )
   {
    if( SampleNumber < nSamplesPerChunk )
    {
        nChunkOffset = (SampleNumber - nSampleBase) / nSamplesPerChunk;
        nSampleOffset = (SampleNumber - nSampleBase) - (nChunkOffset * nSamplesPerChunk);
        nChunkThis += nChunkOffset;
    }
    else
    {
        nChunkOffset = (SampleNumber/nSamplesPerChunk);
        nSampleOffset = (SampleNumber%nSamplesPerChunk);
        nChunkThis += nChunkOffset;
    }
   }
   else
   {
    nChunkOffset = (SampleNumber - nSampleBase) / nSamplesPerChunk;
    nSampleOffset = (SampleNumber - nSampleBase) - (nChunkOffset * nSamplesPerChunk);
    nChunkThis += nChunkOffset;
   }
   for (counter = SampleNumber - nSampleOffset; counter < SampleNumber; counter++)
   {
        nByteOffset += Size(counter+1);
   }

   totNumofChunks = convertFromBetoLe(m_AudStco + 12);
   if( nChunkThis >= totNumofChunks )
   {
        return 0;
   }
   ChunkStart = convertFromBetoLe(m_AudStco + 16 + (nChunkThis * 4));
   return (ChunkStart + nByteOffset);
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    VideoSampleSize
//!
//! Description: For a given video sample number, this functionw will return
//!              size of sample
//! \param: SampleNumber: Sample for which offset is sought
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
int VideoSampleSize(int SampleNum)
{
   int fixedSize = 0;
   int size = 0;
   fixedSize = convertFromBetoLe(m_VidStsz+12);
   if( 0 == fixedSize )
   {
    size = convertFromBetoLe(m_VidStsz+16+(SampleNum*4));
   }
   else
   {
    size = fixedSize;
   }
   return size;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    getSampleOffset
//!
//! Description: For a given video sample number, this function will return
//!              offset of the sample in file
//! \param: SampleNumber: Sample for which offset is sought
//! \return Return: offset
/////////////////////////////////////////////////////////////////////////////////
unsigned int getSampleOffset(int SampleNumber)
{
   int counter = 0;
   int nSampleBase = 0;
    int nChunkThis = 0, nSamplesPerChunk = 1;
   int nChunkNext = 0,nSampleBaseNext = 0;
   int nChunkOffset = 0,nSampleOffset = 0;
   int nByteOffset = 0;
   int ChunkStart = 0;
   unsigned int totNumofChunks = 0;

   //for(counter = 1; counter <= m_NumofChunks; counter++)
   if( m_NumofChunks > 1 )
   {
       for(counter = 0; counter < m_NumofChunks; counter++)
       {
        nChunkThis = convertFromBetoLe(m_VidStsc + 4 + (12 * counter)) - 1;
        nSamplesPerChunk = convertFromBetoLe(m_VidStsc + 4 + (12 * counter) + 4);
        nChunkNext = convertFromBetoLe(m_VidStsc + 4 + (12 * (counter + 1))) - 1;
        nSampleBaseNext = nSampleBase + (nChunkNext - nChunkThis)*nSamplesPerChunk;
        //numofSamples += convertFromBetoLe(m_VidStsc + 8 + (12 * counter));
        if((SampleNumber < nSampleBaseNext) ||(counter == (m_NumofChunks-1)))
        {
            break;
        }
        //if( numofSamples == 0 )
        {
            nSampleBase = nSampleBaseNext;
        }
       }
   }
   else
   {
        for(counter = 0; counter < m_NumofChunks; counter++)
        {
           nChunkThis = convertFromBetoLe(m_VidStsc + 16 + (12 * counter)) - 1;
           nSamplesPerChunk = convertFromBetoLe(m_VidStsc + 16 + (12 * counter) + 4);
           nSampleBase = ((SampleNumber/nSamplesPerChunk)*nSamplesPerChunk);
           nChunkNext = 1;
           nSampleBaseNext = nSampleBase + (nChunkNext - nChunkThis)*nSamplesPerChunk;
           //numofSamples += convertFromBetoLe(m_VidStsc + 8 + (12 * counter));
           if(SampleNumber < nSampleBaseNext)
           {
               break;
           }
           //if( numofSamples == 0 )
           {
               nSampleBase = nSampleBaseNext;
           }
        }
   }

   if( m_NumofChunks > 1 )
   {
       nChunkOffset = (SampleNumber - nSampleBase) / nSamplesPerChunk;
       nSampleOffset = (SampleNumber - nSampleBase) - (nChunkOffset * nSamplesPerChunk);
       nChunkThis += nChunkOffset;
   }
   else
   {
        if( SampleNumber < nSamplesPerChunk )
        {
           nChunkOffset = (SampleNumber - nSampleBase) / nSamplesPerChunk;
           nSampleOffset = (SampleNumber - nSampleBase) - (nChunkOffset * nSamplesPerChunk);
           nChunkThis += nChunkOffset;
        }
        else
        {
           nChunkOffset = (SampleNumber/nSamplesPerChunk);
           nSampleOffset = (SampleNumber%nSamplesPerChunk);
           nChunkThis += nChunkOffset;
        }
   }
   for (counter = SampleNumber - nSampleOffset; counter < SampleNumber; counter++)
    {
        /*if( counter == 0 )
    {
        counter++;
    }*/
    nByteOffset += VideoSampleSize(counter+1);
    }

    totNumofChunks = convertFromBetoLe(m_VidStco + 12);
   if( nChunkThis >= totNumofChunks )
   {
    return 0;
   }
    ChunkStart = convertFromBetoLe(m_VidStco + 16 + (nChunkThis * 4));
    return (ChunkStart + nByteOffset);
}

int SetUnitPTS( unsigned int finalPTS, char isVideoPTS)
{
	if( 1 == isVideoPTS )
	{
		if( NULL == fpVidPTS )
		{
			return (-1);
		}
		fprintf(fpVidPTS,"%d\n",finalPTS);
	}
	else
	{
		if( NULL == fpAudPTS )
		{
			return (-1);
		}
		fprintf(fpAudPTS,"%d\n",finalPTS);
	}
	return 0;
}

int WriteVideoPTS(int counter)
{
	unsigned int finalPTS = 0;
    unsigned int divisionBuffer = 0;
	int num = 0;
	int m_SamplesSofar = 0;
	int numSamplesinChunk = 0;
	int ptsOffset = 0;
	int baseSampleinChunk = 0;
	int sampleOffset = 0;
	float intermediaPTS = 0.0;

	if( m_VideoSampleDuration > 0 )
    {
        finalPTS = (( m_VideoTrckTotalDuration * 1000)/m_TotNumofVideoSamples);
        finalPTS = (finalPTS*counter);
        divisionBuffer = (finalPTS/500);
        if(( divisionBuffer % 2 ) != 0 )
        {
            finalPTS = (( divisionBuffer + 1)* 500);
        }
        finalPTS = (finalPTS/1000);
        SetUnitPTS(finalPTS,1);
    }
	else if(( 0 == m_VideoSampleDuration )&&(m_NumofVidSttsEntries > 0))
	{
		if( 0 == counter )
		{
			finalPTS = 0;
		}
		else
		{
			for(num = 0; num < m_NumofVidSttsEntries; num++)
			{
				numSamplesinChunk = convertFromBetoLe(m_VidStts + 16 + ( num << 3));
				m_SamplesSofar += numSamplesinChunk;
				if( m_SamplesSofar >= counter )
				{
					break;
				}
				else
				{
					ptsOffset = convertFromBetoLe(m_VidStts + 20 + ( num << 3));
					finalPTS += (ptsOffset * numSamplesinChunk);
				}
			}

			if( numSamplesinChunk == 1 )
			{
				finalPTS += convertFromBetoLe(m_VidStts + 20 + ( num << 3));
			}
			else
			{
				baseSampleinChunk = ( m_SamplesSofar - numSamplesinChunk + 1);
				sampleOffset = (( counter - baseSampleinChunk ) + 1);
				ptsOffset = convertFromBetoLe(m_VidStts + 20 + ( num << 3));
				finalPTS += ( ptsOffset * sampleOffset );
			}
		}

		intermediaPTS = ((float)(finalPTS *1000)/(float)m_VideoTrckTimeScale);
		finalPTS = (unsigned int)( intermediaPTS * 1000 );
		divisionBuffer = (finalPTS/500);
        if(( divisionBuffer % 2 ) == 1 )
        {
            finalPTS = (( divisionBuffer + 1)* 500);
        }
		finalPTS = ( finalPTS/1000);
		SetUnitPTS(finalPTS,1);
	}
	return 0;
}

int WriteAudioPTS(int counter)
{
	unsigned int finalPTS = 0;
	unsigned int divisionBuffer = 0;
	int num = 0;
	int m_SamplesSofar = 0;
	int numSamplesinChunk = 0;
	int ptsOffset = 0;
	int baseSampleinChunk = 0;
	int sampleOffset = 0;
	float intermediaPTS = 0.0;
	int intermed1 = 0;
	int intermed2 = 0;
	/*Write time stamp here for sample*/
    if( m_AudioSampleDuration > 0 )
    {
        finalPTS = (( m_AudioTrckTotalDuration*1000)/m_TotNumofAudioSamples);
        finalPTS = (finalPTS*counter);
        divisionBuffer = (finalPTS/500);
        if(( divisionBuffer % 2 ) != 0 )
        {
            finalPTS = (( divisionBuffer + 1)* 500);
        }
        finalPTS = ( finalPTS/1000);

        SetUnitPTS(finalPTS,0);
    }
	else if(( 0 == m_AudioSampleDuration )&&(m_NumofAudSttsEntries > 0))
	{
		if( 0 == counter )
		{
			finalPTS = 0;
		}
		else
		{
			for(num = 0; num < m_NumofAudSttsEntries; num++)
			{
				numSamplesinChunk = convertFromBetoLe(m_AudStts + 16 + ( num << 3));
				m_SamplesSofar += numSamplesinChunk;
				if( m_SamplesSofar >= counter )
				{
					break;
				}
				else
				{
					ptsOffset = convertFromBetoLe(m_AudStts + 20 + ( num << 3));
					finalPTS += (ptsOffset * numSamplesinChunk);
				}
			}
			if( numSamplesinChunk == 1 )
			{
				finalPTS += convertFromBetoLe(m_AudStts + 20 + ( num << 3));
			}
			else
			{
				baseSampleinChunk = ( m_SamplesSofar - numSamplesinChunk + 1);
				sampleOffset = (( counter - baseSampleinChunk ) + 1);
				ptsOffset = convertFromBetoLe(m_AudStts + 20 + ( num << 3));
				finalPTS += ( ptsOffset * sampleOffset );
			}
		}

		/*This juglary is done to overcome the issue of overflow on 32 bit variable*/
		intermed1 = ( finalPTS/m_AudTrckTimeScale);
		intermed2 = ( finalPTS%m_AudTrckTimeScale);
		intermediaPTS = ((float)(intermed2 *10000)/(float)m_AudTrckTimeScale);
		intermed2 = (unsigned int)intermediaPTS;
		intermed2 = (intermed2/10);
		finalPTS = (intermed1 * 1000) + intermed2;
		SetUnitPTS(finalPTS,0);
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    DumpSamplestoFile
//!
//! Description: test function to dump audio data to file buffer
//! \param: counter: Sample which need to be dumped to file buffer
//! \return Return: size
/////////////////////////////////////////////////////////////////////////////////
int DumpSamplestoFile(int counter)
{
   //int counter = 0;
   int offset = 0;
   int size = 0;
   int SizewithAdts = 0;
   unsigned char *temp = NULL;
   unsigned char aacStart[5] = {0xFF,0xF1,0x50, 0x80};// 0x02, 0x1F, 0xFC};
   //unsigned char aacStart1[8] = {0xFF,0xF1,0x50, 0x80, 0x2E, 0x9F, 0xFC};
   unsigned char *writePTR = NULL;
   unsigned char AdtsHeader[4] = {0,0,0,0};
   unsigned char writeBuff[MAX_AUDIO_SAMPLE_SIZE_BEFORE_MALLOC] = "\0";
   unsigned char isMalloced = 0;
   memset(writeBuff,0x0,(MAX_AUDIO_SAMPLE_SIZE_BEFORE_MALLOC));

   WriteAudioPTS(counter);
   //for( counter = 0; counter <  m_TotNumofAudioSamples; counter++)
   {
    offset = getOffset(counter);
    fseek(fp,offset,SEEK_SET);
    size = Size(counter+1);
    if( size > MAX_AUDIO_SAMPLE_SIZE_BEFORE_MALLOC)
	{
		writePTR = (unsigned char *)GaloisMalloc((size+1)*sizeof(unsigned char));
		printf("\nNeed to malloc as size of audio sample is %d\n",size);
		isMalloced = 1;
	}
	else
	{
		writePTR = writeBuff;
	}
    writePTR = (unsigned char *)GaloisMalloc((size+1)*sizeof(unsigned char));
    if( NULL != writePTR )
    {
        memset(writePTR,'\0',(size+1));
        fread(writePTR,1,size,fp);
        SizewithAdts = (size + 7);
        temp = (unsigned char *)&SizewithAdts;
        switch(m_pAudioVersionNum)
    {
        case 1:
        aacStart[2] = 0x00; //AAC Main
        break;
       case 2:
        aacStart[2] = 0x01 <<6; //AAC LC (Low complexity profile
       break;
       case 3:
        aacStart[2] = 0x02<<6; //AAC SSR Scalable Sampling Rate profile
        break;
       case 4:
        aacStart[2] = 0x03<<6; //AAC LTP
        break;
       default:
        aacStart[2] = 0x01<<6; //AAC LC
        break;
    }
    aacStart[2] |= (( m_pAudiosamplingFreq & 0x0F ) << 2);
    aacStart[2] |= (( m_pAudioNumChannels & 0x07 ) >> 2);
    aacStart[3] |= (( m_pAudioNumChannels & 0x07 ) << 6);
    aacStart[3] |= ((temp[1] & 0x18) >>3);
    fwrite(aacStart,1,4,fpAAC);

    //writeAVInputBuf(1,aacStart,4);
    AdtsHeader[2] = 0xFC;
    AdtsHeader[0] = ((temp[1]& 0x07) << 5);
    AdtsHeader[0] |= ((temp[0]& 0xF8) >> 3);
    AdtsHeader[1] =  ((temp[0]&0x07) << 5);
    AdtsHeader[1] |= 0x1F;//buffer fullness is set to FFE.
#ifdef ENABLE_FILE_WRITE
    fwrite(AdtsHeader,1,3,fpAAC);
#endif
    //writeAVInputBuf(1,AdtsHeader,3);
#ifdef ENABLE_FILE_WRITE
    fwrite(writePTR,1,size,fpAAC);
#endif
    //writeAVInputBuf(1,writePTR,size);
    if( 1 == isMalloced )
    {
    	GaloisFree(writePTR);
	}
    }
    else
    {
        printf("\nFailed in malloc at DumpSamplestoFile, for counter =%d\n",counter);
    }
   }

   return 0;
}

Errtype_e getavcCBox(unsigned char *m_VidStsd)
{
	unsigned char *pStsdBox = m_VidStsd;
	int bfound = 0;
	int stsdLength = m_StsdLength;
	int avccLength = 0;
	int position = 0;
   	char arr[5] = {'\0','\0','\0','\0','\0'};

   	if(( NULL == m_VidStsd )||( m_StsdLength <= 0 ))
	{
	   return DMX_ERR_INVALID_PARAM;
	}

	while(stsdLength--)
	{
		if(*pStsdBox == 'a')
		{
			arr[0] = *pStsdBox;
			arr[1] = *++pStsdBox;
			arr[2] = *++pStsdBox;
			arr[3] = *++pStsdBox;
			if( 0 == strcmp(arr,"avcC"))
			{
				bfound = 1;
		#if DMX_FILE_LEVEL_PRINT_ENABLE
				printf("\nFound stts for audio\n");
		#endif
				break;
			}
			else
			{
				pStsdBox--;
				pStsdBox--;
			}
		}
		else
		{
			pStsdBox++;
		}
	}

	if( 1 == bfound )
    {
		position = (pStsdBox - m_VidStsd - 7);
    	avccLength = convertFromBetoLe(m_VidStsd + position);
    	m_VidAvcc = (m_VidStsd + position);
	}
	else
	{
		printf("\nAvcc is not present in video stsd\n");
		return DMX_ERR_NON_SUPPORTED_ENCODING;
	}
	return DMX_ERR_OK;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    WriteVideoDecodeerRelatedInfo
//!
//! Description: This function will write the sps and pps param into PE buffer
//! \param: m_VidStsd: Stsd box, which contains the h.264 decoding related data
//! \return Return: error code
/////////////////////////////////////////////////////////////////////////////////
Errtype_e WriteVideoDecodeerRelatedInfo(unsigned char *m_VidStsd)
{
   int StsdSize = convertFromBetoLe(m_VidStsd);
   char arr[5] = {'\0','\0','\0','\0','\0'};
   unsigned char startVal[5] = {0x00,0x00,0x00,0x01};
   int avcCSize = 0;
   int counter = 0;
   int ppsSize = 0,sqsSize = 0;

   m_VidAvcc = (m_VidStsd + 0x66);
   for(counter = 0; counter < 4; counter++)
   {
    arr[counter] = *(m_VidAvcc + 4 + counter);
   }
   if( 0 != strcmp(arr,"avcC"))
   {
      printf("\nThe file doesn't have avcC box in appropriate place,search again\n");
	  if( DMX_ERR_OK != getavcCBox(m_VidStsd))
	  {
	      return DMX_ERR_NON_SUPPORTED_ENCODING;
	  }
   }

   avcCSize = convertFromBetoLe(m_VidAvcc);

   m_lengthByte = (*(m_VidAvcc + 12) & 0x03)+1;
   printf("\n++++Length byte is %d\n",m_lengthByte);

   if( avcCSize <  StsdSize )
   {
      avcCSize -= 8;
   }

   /*Now write it in file*/
#ifdef ENABLE_FILE_WRITE
   if( NULL != fpH264 )
#endif
   {
       sqsSize = *(m_VidAvcc + 15);
#ifdef ENABLE_FILE_WRITE
       fwrite((m_VidAvcc + 16),1,sqsSize,fpH264);
#endif
       //writeAVInputBuf(0,(m_VidAvcc + 16),sqsSize);
#ifdef ENABLE_FILE_WRITE
       fwrite(startVal,1,4,fpH264);
#endif
       //writeAVInputBuf(0,startVal,4);
       //ppsSize = *(m_VidAvcc + avcCSize + 3);
       ppsSize = *(m_VidAvcc + (sqsSize + 15) + 3);
#ifdef ENABLE_FILE_WRITE
       fwrite((m_VidAvcc + (sqsSize + 15) +4),1, ppsSize,fpH264);
#endif
       //writeAVInputBuf(0,(m_VidAvcc + (sqsSize + 15)+ 4),ppsSize);
   }
#ifdef ENABLE_FILE_WRITE
   else
   {
       printf("\nVideo file is not open1\n");
   }
#endif
   return 0;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Function:    DumpVideoSamplestoFile
//!
//! Description: Test function to dumo the video sample in PE buffer
//! \param: counter: Sample which need to be dumped
//! \return Return: error code
/////////////////////////////////////////////////////////////////////////////////
int DumpVideoSamplestoFile(int counter)
{
   //int counter = 0;
   unsigned int offset = 0;
   int size = 0;
   unsigned char *writePTR = NULL;
   unsigned char *writePTROrig = NULL;
   unsigned char startVal[5] = {0x00,0x00,0x00,0x01};
   int writeLen = 0;
   int consumedBytes = 0;
   unsigned char writeBuff[MAX_VIDEO_SAMPLE_SIZE_BEFORE_MALLOC] = "\0";
   int isMalloced = 0;

   memset(writeBuff,0x0,(MAX_VIDEO_SAMPLE_SIZE_BEFORE_MALLOC));
   WriteVideoPTS(counter);

   if( 0 == counter )
   {
#ifdef ENABLE_FILE_WRITE
      if( NULL != fpH264 )
#endif
      {
#ifdef ENABLE_FILE_WRITE
          fwrite(startVal,1,4,fpH264);
#endif
          //writeAVInputBuf(0,startVal,4);
          if( DMX_ERR_OK != WriteVideoDecodeerRelatedInfo(m_VidStsd))
          {
			  return DMX_ERR_FUNC_FAILED;
		  }
      }
#ifdef ENABLE_FILE_WRITE
      else
      {
          printf("\nVideo file is already closed\n");
          return DMX_ERR_FUNC_FAILED;
      }
#endif
   }
   //for( counter = 0; counter <  m_TotNumofVideoSamples; counter++)
   {
    offset = getSampleOffset(counter);
    fseek(fp,offset,SEEK_SET);
    size = VideoSampleSize(counter+1);
	if( size > MAX_VIDEO_SAMPLE_SIZE_BEFORE_MALLOC)
	{
		writePTR = (unsigned char *)GaloisMalloc((size+1)*sizeof(unsigned char));
		printf("\nNeed to malloc as size of video sample is %d\n",size);
		isMalloced = 1;
		writePTROrig = writePTR;
	}
	else
	{
		writePTR = writeBuff;
	}
    if( NULL != writePTR )
    {
        memset(writePTR,'\0',(size+1));
#ifdef ENABLE_FILE_WRITE
        fread(writePTR,1,size,fp);
        //fwrite(startVal,1,4,fpH264);
#endif
        //writeAVInputBuf(0,startVal,4);
		while( consumedBytes < size )
		{
			#ifdef ENABLE_FILE_WRITE
			fwrite(startVal,1,4,fpH264);
			if( 4 == m_lengthByte )
			{
				writeLen = convertFromBetoLe(writePTR);
				fwrite((writePTR + 4),1,writeLen,fpH264);
				consumedBytes = ( consumedBytes + writeLen + 4);
				writePTR = (writePTR + writeLen + 4);
			}
			else
			{
				writeLen = convertFromBetoLe16Bit(writePTR);
				fwrite((writePTR + 2),1,writeLen,fpH264);
				consumedBytes = ( consumedBytes + writeLen + 2);
				writePTR = (writePTR + writeLen + 2);
			}
			#endif
		}
        //writeAVInputBuf(0,(writePTR + 2),(size - 2));
		if( 1 == isMalloced )
		{
			GaloisFree(writePTROrig);
			writePTR = NULL;
			writePTROrig = NULL;
		}
    }
    else
    {
        printf("\nFailed in malloc in DumpVideoSamplestoFile,counter=%d\n",counter);
    }
   }

   return DMX_ERR_OK;
}

void cleanupAllpointers()
{
   if( NULL != m_MoovBox )
   {
       free(m_MoovBox);
	   m_MoovBox = NULL;
   }
   m_VidTrck = NULL;
   m_VidStbl = NULL;
   m_VidStsc = NULL;
   m_VidStsz = NULL;
   m_VidStco = NULL;
   m_VidStts = NULL;
   m_VidStss = NULL;
   m_VidStsd = NULL;
   m_AudTrck = NULL;
   m_AudStbl = NULL;
   m_AudStsc = NULL;
   m_AudStsz = NULL;
   m_AudStco = NULL;
   m_AudStsd = NULL;
   m_AudStts = NULL;
   m_FirstTrck = NULL;
   m_SecondTrck = NULL;
}

void initallGlobalVariables()
{
	totMemoryUsed = 0;
	curr_offset = 0;
	m_count = 2;
	state = 0;
	m_MoovBox = NULL;
	m_TimeScale = 0;
	m_TotalDuration = 0;
	m_FirstTrck = NULL;
	m_SecondTrck = NULL;
	m_AudTrck = NULL;
	m_VidTrck = NULL;
	m_VideoTrckTotalDuration = 0;
	m_VideoTrckDuration = 0;
	m_VideoTrckTimeScale = 0;
	m_VidStbl = NULL;
	m_VidStsc = NULL;
	m_VidStsz = NULL;
	m_VidStco = NULL;
	m_VidStsd = NULL;
	m_VidAvcc = NULL;
	m_VidStts = NULL;
	m_VidStss = NULL;
	m_AudStbl = NULL;
	m_AudStsc = NULL;
	m_AudStsz = NULL;
	m_AudStco = NULL;
	m_AudStsd = NULL;
	m_AudStts = NULL;
	m_TotNumofVideoSamples = 0;
	m_NumofChunks = 0;
	m_VideoSampleDuration = 0;
	m_AudioTrckTotalDuration = 0;
	m_NumofAudioChunks = 0;
	m_TotNumofAudioSamples = 0;
	m_pAudioVersionNum = 0;
	m_pAudioNumChannels = 0;
	m_pAudiosamplingFreq = 0;
	m_AudioSampleDuration = 0;
	m_lengthByte = 0;
	m_NumofAudSttsEntries = 0;
	m_NumofVidSttsEntries = 0;
	m_AudTrckTimeScale = 0;
}

Errtype_e StartMp4Demux(void)
{
	int audioCounter = 0;
	int videoCounter = 0;
	int currentPos = 0;
	int freelength = 0;
	int firstvidcounterOffset = 0;
	int firstaudcounterOffset = 0;
	char bFound = 0;
	char arr[9] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0'};

	initallGlobalVariables();

	while( m_count--)
	{
		switch(state)
		{
			case STATE_INITIAL:
			case STATE_HEADER:
			{
				if( DMX_ERR_OK != parseMp4Header(fp))
				{
					printf("\nFailed in parseMp4Header\n");
					return DMX_ERR_FUNC_FAILED;
				}
			}
			break;
		}
	}

	currentPos = ftell(fp);
#if DMX_FILE_LEVEL_PRINT_ENABLE
    printf("\nImmediately after moov box, position is 0x%x\n",currentPos);
#endif

    fread(arr,1,8,fp);
    if(( arr[4] == 'm' )
        &&(arr[5] == 'd')
        &&(arr[6] == 'a')
        &&(arr[7] == 't'))
    {
#if DMX_FILE_LEVEL_PRINT_ENABLE
        printf("\nReceived mdat box here\n");
#endif
    }
    else
    {
		printf("\nThis is not mdat box\n");
		freelength = convertFromBetoLe(arr);
		freelength = ( freelength - 8);
		fseek(fp,freelength,SEEK_CUR);
		while(fread(arr,1,8,fp))
		{
			if(( arr[4] == 'm' )
			  &&(arr[5] == 'd')
			  &&(arr[6] == 'a')
			  &&(arr[7] == 't'))
			{
			#if DMX_FILE_LEVEL_PRINT_ENABLE
				printf("\nReceived mdat box here\n");
			#endif
				bFound = 1;
				break;
			}
			else
			{
				freelength = convertFromBetoLe(arr);
				freelength = ( freelength - 8);
				fseek(fp,freelength,SEEK_CUR);
			}
		}

		if( 0 == bFound )
		{
			printf("\nThere are no mdat box in file,so return from here\n");
			return DMX_ERR_NON_SUPPORTED_FORMAT;
		}

	}
    currentPos = ftell(fp);
#if DMX_FILE_LEVEL_PRINT_ENABLE
    printf("\nImmediately after moov box, position is %d,tot audio samples are %d, tot video samples are %d\n",currentPos,m_TotNumofAudioSamples,m_TotNumofVideoSamples);
	printf("\nFirst audio sample offset = %d,First video sample offset=%d\n",getOffset(0),getSampleOffset(0));
#endif

	/*NOw we are going to do a ghapla,this is because one file from IL which is non standard*/
	if(( currentPos != getOffset(0))&&(currentPos != getSampleOffset(0)))
	{
		firstvidcounterOffset = getSampleOffset(0);
		firstaudcounterOffset = getOffset(0);
		if( firstaudcounterOffset < firstvidcounterOffset )
		{
			freelength = ( firstaudcounterOffset - currentPos );
			fseek ( fp , freelength , SEEK_CUR );
		}
		else
		{
			freelength = ( firstaudcounterOffset - currentPos );
			fseek ( fp , freelength , SEEK_CUR );
		}
		currentPos = ftell(fp);
		printf("\nAfter ghapla, the current pos is 0x%x\n",currentPos);
	}

	while((audioCounter < m_TotNumofAudioSamples)||(videoCounter < m_TotNumofVideoSamples))
    {
        currentPos = ftell(fp);
		//printf("\nSo far completed,currentPos=%d,audioCounter=%d,videoCounter=%d\n",currentPos,audioCounter,videoCounter);
        /*First check with audio*/
        if(audioCounter < m_TotNumofAudioSamples)
        {
            if( currentPos == getOffset(audioCounter))
            {
                DumpSamplestoFile(audioCounter);
                audioCounter++;
            }
            else if((videoCounter < m_TotNumofVideoSamples)&&( currentPos == getSampleOffset(videoCounter)))
            {
                if(DMX_ERR_OK !=  DumpVideoSamplestoFile(videoCounter))
                {
					printf("\nFailed to write video samples\n");
					break;
				}
                videoCounter++;
            }
            else
            {
				printf("\nWe are looping because we are here,some problem, break here\n");
				break;
            }
        }
        else if(videoCounter < m_TotNumofVideoSamples)
        {
            if( currentPos == getSampleOffset(videoCounter))
            {
                if(DMX_ERR_OK != DumpVideoSamplestoFile(videoCounter))
                {
					printf("\nFailed to write video samples\n");
					break;
				}
                videoCounter++;
            }
			else
			{
				printf("\nWe are looping because we are here,some problem1, break here\n");
				break;
			}

        }
   }

	printf("\nWe are done with demux\n");
	return DMX_ERR_OK;
}

int main()
{
	fp = fopen(INPUT_FILE_PATH,"rb");
	fpAAC = fopen(OUTPUT_AUDIO_ES_PATH,"wb");
	fpH264 = fopen(OUTPUT_VIDEO_ES_PATH,"wb");
	fpVidPTS = fopen(OUTPUT_VIDEO_PTS_PATH,"w");
	fpAudPTS = fopen(OUTPUT_AUDIO_PTS_PATH,"w");
	if(( NULL == fp )||( NULL == fpAAC )||( NULL == fpH264 ))
	{
		printf("\nFailed to open the file\n");
		return -1;
	}
	printf("\nFile openned successfully\n");
	if( DMX_ERR_OK != StartMp4Demux())
	{
		printf("\nDemux failed\n");
		getch();
	}
	printf("\nTotal memory allocated is %d\n",totMemoryUsed);
	fclose(fp);
	fclose(fpAAC);
	fclose(fpH264);
	fclose(fpVidPTS);
	fclose(fpAudPTS);
	cleanupAllpointers();
	getch();
	return 0;
}