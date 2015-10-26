#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "inttypes.h"
#include "types.h"
#include "stdint.h"
#include "sys/types.h"
#include "flvdemux.h"

FLV_DMX_STATE m_state = FLV_DMX_STATE_NONE;
char m_FileHasVideo = 0;
char m_FileHasAudio = 0;
unsigned int m_NumBytesconsumed = 0;
unsigned int m_NumBytesExpected = 0;
char isMetadataFound = 0;
FLV_SEEK_POINT curSeekPnt;
FLV_DMX_AVC_STATE m_avcPktState = FLV_DMX_AVC_STATE_NONE;
FLV_DMX_AAC_STATE m_aacPktState = FLV_DMX_AAC_STATE_NONE;
FILE *fpH264 = NULL;
FILE *fpAAC = NULL;
FILE *fpDTS = NULL;

const int sndCompressMask = 0xF0;
const int sndRateMask = (0x3 << 2);
const int sndBitMask = 0x2;
const int sndChannelMask = 0x1;
unsigned char ADTS[7];
int m_fileSize = 0;

unsigned int ReadUnsigned(char *bp, int size, char *error)
{
	unsigned int value = 0;
	char readValue = 0;
	int c = 0; 
	for ( c=0; c<size; c++)
	{
		readValue = bp[c];
		value |= ( value << 8 ) | readValue;
	}
	return (unsigned int)value;
}

unsigned int getUnsigned(unsigned char *buff, int size)
{
	unsigned int value = 0;
	unsigned char readValue;
	int c = 0;
	if(buff == NULL)
	{
		return 0;
	}
	for( c=0; c<size; c++)
	{
		readValue = 0;
		readValue = buff[c];
		//value |= ( value << 8 ) | readValue;
		value = ( value << 8 ) ;
		value |= readValue ;
	}
	return value;
}

static unsigned int getTagTime(unsigned char *pHeader) 
{ 
	printf("-->%s\r\n", __FUNCTION__);

	if( NULL == pHeader )
	{
		return 0;
	}
	return (((unsigned)pHeader[6] << 24) |
			((unsigned)pHeader[3] << 16) |
			((unsigned)pHeader[4] <<  8) |
			((unsigned)pHeader[5])); 
}

static unsigned int getDataLen(unsigned char *pHeader)
{ 
	printf("-->%s\r\n", __FUNCTION__);
	if( NULL == pHeader )
	{
		return 0;
	}	
	return (((unsigned)pHeader[0] << 16) |
			((unsigned)pHeader[1] <<  8) |
			((unsigned)pHeader[2])); 
}

static int flvScrGetString(unsigned char *instrBuf, char*outstrBuf)
{
	unsigned short length = getUnsigned(instrBuf,2);
	int i =0;
	printf("-->%s\r\n", __FUNCTION__);
	if(length >254)
	{
		return -1;
	}

	for(i =0;i<length;i++)
	{
		outstrBuf[i] = instrBuf[i+2];
		outstrBuf[length] = '\0';
	}
	return length+2;
}

unsigned char* getString(unsigned char *buff)
{
	static unsigned char revBuf[8];
	int c = 0;
	static unsigned char *durPtr = NULL;
	printf("-->%s\r\n", __FUNCTION__);
	durPtr = (unsigned char *)revBuf;
	if(buff == NULL)
	{
		return 0;
	}

	for(c=0; c<8; c++)
	{
		revBuf[7-c]= buff[c];
	}
	return durPtr;
}

double* getDbl(unsigned char *buff)
{
	static char revBuf[8];
	int c = 0;
	printf("-->%s\r\n", __FUNCTION__);
	if(buff == NULL)
	{
		return 0;
	}

	for(c=0; c<8; c++)
	{
		revBuf[7-c]= buff[c];
	}
	return (double*)revBuf;
}

Errtype_e initiateflvdemux(FILE *fp)
{
	flv_header header;
	unsigned char destBuf[9] = "\0";
	unsigned char readBytes = 0;

	printf("-->%s\r\n", __FUNCTION__);
	memset(&curSeekPnt,0x0,sizeof(curSeekPnt));

	if( NULL == fp )
	{
		return DMX_ERR_INVALID_PARAM;
	}

	//readBytes = fread(destBuf,sizeof(unsigned char),9,fp);

	printf("struct size :%ld\r\n", sizeof(header));
	readBytes = fread(header.signature, 1, sizeof(header.signature), fp);
	printf("signature :%c%c%c\r\n", header.signature[0], header.signature[1], header.signature[2]);

	readBytes += fread(&header.version, 1, sizeof(header.version), fp);
	printf("version   :%d\r\n", header.version);

	readBytes += fread(&header.flags, 1, sizeof(header.flags), fp);
	printf("flags     :%d\r\n", header.flags);

	readBytes += fread(&header.offset, 1, sizeof(header.offset), fp);
	printf("offset    :%x\r\n", swap_uint32(header.offset));
	printf("readBytes :%x\r\n", readBytes);

	if( 9 == readBytes )
	{
		if ((header.signature[0] == 'F') &&  (header.signature[1] == 'L') && (header.signature[2] == 'V') )
		{
			printf("Proper flv file\r\n");
			m_FileHasVideo = header.flags & FLV_HAS_VIDEO;
			m_FileHasAudio = header.flags & FLV_HAS_AUDIO;
			m_NumBytesconsumed = 9;
			m_NumBytesExpected = 5;
			m_state = FLV_DMX_STATE_FLV_HDR;
		}
		else
		{
			return DMX_ERR_NON_SUPPORTED_FORMAT;
		}
	}
	else
	{
		return DMX_ERR_SRC_READ_FAILED;
	}
	return DMX_ERR_OK;
}

Errtype_e beginNewTag(unsigned char *tempBuf, unsigned int size)
{
	printf("-->%s\r\n", __FUNCTION__);
	if(( NULL == tempBuf )||( 0 == size ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	printf("-->type :%d\r\n", tempBuf[4]);

	switch(tempBuf[4])
	{
		case FLV_TAGTYPE_VIDEO:
			{
				m_state = FLV_DMX_STATE_TAG_V;
				m_NumBytesExpected = TAG_HEADER_SIZE;
			}
			break;

		case FLV_TAGTYPE_AUDIO:
			{
				m_state = FLV_DMX_STATE_TAG_A;
				m_NumBytesExpected = TAG_HEADER_SIZE;
			}
			break;

		case FLV_TAGTYPE_SCRIPT:
			{
				m_state = FLV_DMX_STATE_TAG_D;
				m_NumBytesExpected = TAG_HEADER_SIZE-1;
			}
			break;

		default:
			{
				m_state = FLV_DMX_STATE_TAG_RSRVD;
				m_NumBytesExpected = TAG_HEADER_SIZE-1;;
			}
			break;
	}
	return DMX_ERR_OK;
}

Errtype_e OnFlvTagData(unsigned char *tempBuf, unsigned int size)
{
	printf("-->%s\r\n", __FUNCTION__);
	if(( NULL == tempBuf )||( 0 == size ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	m_NumBytesExpected = getDataLen(tempBuf);
	printf("m_NumBytesExpected :%d\r\n", m_NumBytesExpected);
	if( isMetadataFound == 0 )
	{
		m_state = FLV_DMX_STATE_FLV_TAG_META_DATA;
		//isMetadataFound = 1;
	}
	else
	{
		m_state = FLV_DMX_STATE_FLV_TAG_END;
	}
	return DMX_ERR_OK;
}

Errtype_e MV_getFileDuration(unsigned char *buf, int size )
{
	unsigned char *durPtr = buf;
	unsigned char arr[10] = "\0";
	int counter = 0;
	double *num = NULL;
	unsigned char *durString = NULL;
	double duration = 0.0;
	char isDurFound = 0;
	printf("-->%s\r\n", __FUNCTION__);

	if(( NULL == buf )||( size <= 0 ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	while(size-- > 0 )
	{
		if( *durPtr == 'd')
		{
			for( counter = 0; counter < 8; counter++)
			{
				arr[counter] = *durPtr++;
			}
			if( 0 == strcmp((char *)arr,"duration"))
			{
				isDurFound = 1;
				break;

			}
			else
			{
				durPtr = durPtr - 7;
				counter = 0;
			}
		}
		else
		{
			durPtr++;
		}
	}

	if( 0 == *durPtr )
	{
		if( 1 == isDurFound )
		{
			durPtr++;
			durString = getString(durPtr);
			memcpy(&duration,durString,8);
			printf("Duration is %2.1f\r\n",duration);
		}
	}
	else
	{   
	}
	return DMX_ERR_OK;;
}

Errtype_e MV_getFileWidth(unsigned char *buf,int size )
{
	unsigned char *durPtr = buf;
	unsigned char arr[10] = "\0";
	int counter = 0;
	double *num = NULL;
	double width = 0.0;
	char isWidthFound = 0;
	printf("-->%s\r\n", __FUNCTION__);

	if(( NULL == buf )||( size <= 0 ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	while(size-- > 0 )
	{
		if( *durPtr == 'w')
		{
			for( counter = 0; counter < 5; counter++)
			{
				arr[counter] = *durPtr++;
			}
			if( 0 == strcmp((char *)arr,"width"))
			{
				isWidthFound = 1;
				break;
			}
			else
			{
				durPtr = durPtr - 4;
				counter = 0;
			}
		}
		else
		{
			durPtr++;
		}
	}

	if( 0 == *durPtr )
	{
		if( 1 == isWidthFound )
		{
			durPtr++;
			num = getDbl(durPtr);
			width = *num;
			printf("width is %f\r\n",width);
		}
		else
		{    
		}
	}
	else
	{    
	}

	return 0;
}

Errtype_e MV_getFileHeight(unsigned char *buf, int size )
{
	unsigned char *durPtr = buf;
	unsigned char arr[10] = "\0";
	int counter = 0;   
	double *num = NULL;
	double height = 0.0;
	char isHeightFound = 0;

	printf("-->%s\r\n", __FUNCTION__);
	if(( NULL == buf )||( size <= 0 ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	while(size-- > 0 )
	{
		if( *durPtr == 'h')
		{
			for( counter = 0; counter < 6; counter++)
			{
				arr[counter] = *durPtr++;
			}
			if( 0 == strcmp((char *)arr,"height"))
			{
				isHeightFound = 1;
				break;
			}
			else
			{
				durPtr = durPtr - 5;
				counter = 0;
			}
		}
		else
		{
			durPtr++;
		}
	}

	if( 0 == *durPtr )
	{
		if( 1 == isHeightFound )
		{
			durPtr++;
			num = getDbl(durPtr);
			height = *num;        
			printf("height is %f\r\n",height);        
		}
		else
		{    
		}
	}
	else
	{    
	}
	return DMX_ERR_OK;
}

Errtype_e MV_getFileSize(unsigned char *buf, int size )
{
	unsigned char *durPtr = buf;
	unsigned char arr[12] = "\0";
	int counter = 0;
	double *num = NULL;
	double Fsize = 0.0;
	char isSizeFound = 0;

	printf("-->%s\r\n", __FUNCTION__);
	if(( NULL == buf )||( size <= 0 ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	while(size-- > 0 )
	{
		if( *durPtr == 'b')
		{
			for( counter = 0; counter < 10; counter++)
			{
				arr[counter] = *durPtr++;
			}
			if( 0 == strcmp((char *)arr,"bytelength"))
			{
				isSizeFound = 1;
				break;
			}
			else
			{
				durPtr = durPtr - 9;
				counter = 0;
			}
		}
		else
		{
			durPtr++;
		}
	}

	if( 0 == *durPtr )
	{
		if( 1 == isSizeFound )
		{
			durPtr++;
			num = getDbl(durPtr);
			Fsize = *num;
			m_fileSize = Fsize;
			printf("Finally the size is %f\r\n",Fsize);        
		}
		else
		{    
		}
	}
	else
	{    
	}
	return DMX_ERR_OK;
}

Errtype_e MV_getFrameRate(unsigned char *buf, int size )
{
	unsigned char *durPtr = buf;
	unsigned char arr[12] = "\0";
	int counter = 0;   
	double *num = NULL;
	double Fsize = 0.0;
	char isFrameRateFound = 0;

	printf("-->%s\r\n", __FUNCTION__);
	if(( NULL == buf )||( size <= 0 ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	while(size-- > 0 )
	{
		if( *durPtr == 'f')
		{
			for( counter = 0; counter < 9; counter++)
			{
				arr[counter] = *durPtr++;
			}
			if( 0 == strcmp((char *)arr,"framerate"))
			{
				isFrameRateFound = 1;
				break;
			}
			else
			{
				durPtr = durPtr - 8;
				counter = 0;
			}
		}
		else
		{
			durPtr++;
		}
	}

	if( 0 == *durPtr )
	{
		if( 1 == isFrameRateFound )
		{
			durPtr++;
			num = getDbl(durPtr);
			Fsize = *num;        
			printf("Finally the framerate is %f\r\n",Fsize);
		}
		else
		{        
		}
	}
	else
	{    
	}
	return 0;
}

Errtype_e getMetadataInfo(unsigned char *buf, int size)
{
	char str[256] = "\0";
	int cur = 0;
	int length = 0;

	printf("-->%s\r\n", __FUNCTION__);
	if(( NULL == buf )||( 0 == size ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	if( FLV_SCRIPT_STRING == buf[cur++])
	{
		length = flvScrGetString(&buf[1], str);
		cur = (cur + length);
		if(0==strcmp(str, "onMetaData"))
		{
			buf = buf + cur;
			MV_getFileDuration(buf,(size-cur));
			MV_getFileWidth(buf,(size-cur));
			MV_getFileHeight(buf,(size-cur));
			MV_getFileSize(buf,(size-cur));
			MV_getFrameRate(buf,(size-cur));
		}
	}
	m_state = FLV_DMX_STATE_FLV_TAG_END;
	m_NumBytesExpected = 5;
	isMetadataFound = 1;
	return DMX_ERR_OK;
}

static Errtype_e OnFlvTagVideo(unsigned char *inFlvBuf, int size)
{
	printf("-->In OnFlvTagVideo\r\n");
	if(( NULL == inFlvBuf )||( 0 == size ))
	{
		return DMX_ERR_INVALID_PARAM;
	}
	curSeekPnt.decodeTime = getTagTime(inFlvBuf);
	curSeekPnt.dataSize = getDataLen(inFlvBuf);
	curSeekPnt.vidDes.videoCodec = (inFlvBuf[10] & VIDEO_CODEC_MASK);
	curSeekPnt.vidDes.videoFrameType = (inFlvBuf[10]&FRAME_TYPE_MASK)>>4;;
	curSeekPnt.keyFrame = (inFlvBuf[10]&FRAME_TYPE_KEY)>>4;

	if(curSeekPnt.vidDes.videoCodec != 7) /*The video encoding type is non AVC*/
	{
		return DMX_ERR_NON_SUPPORTED_FORMAT;
	}
	else
	{
		m_avcPktState = FLV_DMX_AVC_STATE_NONE;
		m_state = FLV_DMX_STATE_V_DATA;
		m_NumBytesExpected = 4;// This four bytes will tell what kind of frame it is*/
	}
	return DMX_ERR_OK;
}

int SetUnitPTS( unsigned int finalPTS, char isVideoPTS)
{	
	printf("-->%s\r\n", __FUNCTION__);
	if( NULL == fpDTS )
	{
		return (-1);
	}
	if( 1 == isVideoPTS )
	{
		fprintf(fpDTS,"Video PTS = %d\n",finalPTS);
	}
	else
	{
		fprintf(fpDTS,"Audio PTS=%d\n",finalPTS);
	}

	return 0;
}

Errtype_e processConfigRecFrame(unsigned char *inFlvBuf, int size,int *LengthSize)
{
	unsigned char len[5] = {0,0,0,1,'\0'};
	unsigned char *tmpbuf = inFlvBuf;
	int counter = 0;
	int consumedBytes = 4;
	int seqParamSetLen = 0,numPicParamSets= 0,numSeqParamSets=0;
	int picParamSetLen = 0;

	printf("-->%s\r\n", __FUNCTION__);

	if(( NULL == inFlvBuf )||( 0 == size ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	*LengthSize = (tmpbuf[4]&0x03) +1; //Fifth byte
	numSeqParamSets = tmpbuf[5] & 0x1F; //sixth byte
	consumedBytes += 2;
	for(counter = 0; counter < numSeqParamSets; counter++)
	{
		seqParamSetLen = getUnsigned(&tmpbuf[consumedBytes],2);
		consumedBytes += 2;
		SetUnitPTS(curSeekPnt.decodeTime,1);
		if( 4 == fwrite(len,1,4,fpH264)) //Write the AVC frame start
		{
			fwrite(&tmpbuf[consumedBytes],1,seqParamSetLen,fpH264);
			consumedBytes +=seqParamSetLen;
		}
	}
	numPicParamSets = tmpbuf[consumedBytes];
	consumedBytes++;
	for(counter = 0; counter < numPicParamSets; counter++)
	{
		picParamSetLen = getUnsigned(&tmpbuf[consumedBytes],2);
		consumedBytes +=2; 
		if( 4 == fwrite(len,1,4,fpH264)) //Write the AVC frame start
		{			
			fwrite(&tmpbuf[consumedBytes],1,picParamSetLen,fpH264);
			consumedBytes += picParamSetLen;			
		}
	}
	m_state = FLV_DMX_STATE_FLV_TAG_END;
	m_NumBytesExpected = 5;
	return DMX_ERR_OK;
}

Errtype_e processAVCNALUFrame(unsigned char *inFlvBuf, int size,int LengthSize)
{
	int consumedBytes = 0;
	unsigned char *tmpbuf = inFlvBuf;
	unsigned char len[5] = {0,0,0,1,'\0'};
	unsigned int nalulen = 0;

	printf("-->%s\r\n", __FUNCTION__);

	if(( NULL == inFlvBuf )||( 0 == size )||(0 == LengthSize))
	{
		return DMX_ERR_INVALID_PARAM;
	}
	SetUnitPTS(curSeekPnt.decodeTime,1);
	while(consumedBytes < size)
	{
		if( 2 != LengthSize )
		{			
			nalulen = getUnsigned(tmpbuf,4);
			tmpbuf+=4;
			consumedBytes+=4;
		}
		else
		{
			nalulen = getUnsigned(tmpbuf,2);
			tmpbuf+=2;
			consumedBytes+=2;
		}
		if( nalulen > (size - consumedBytes)) //Error condition
		{
			break;
		}
		if( 4 == fwrite(len,1,4,fpH264)) //Write the AVC frame start
		{
			fwrite(tmpbuf,1,nalulen,fpH264); //Write videoo data to file
		}
	}
	m_state = FLV_DMX_STATE_FLV_TAG_END;
	m_NumBytesExpected = 5;
	m_avcPktState= FLV_DMX_AVC_STATE_NONE;
	return DMX_ERR_OK;
}

Errtype_e OnVideoData(unsigned char *inFlvBuf, int size)
{
	static int LengthSize = 0;

	printf("-->%s\r\n", __FUNCTION__);

	if(( NULL == inFlvBuf )||( 0 == size ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	switch(m_avcPktState)
	{
		case FLV_DMX_AVC_STATE_NONE:
			{
				switch(inFlvBuf[0])
				{
					case 0: //Sequence header
						{
							m_avcPktState = FLV_DMX_AVC_DECODER_CONFIG_REC;
							m_NumBytesExpected = (curSeekPnt.dataSize - 5); //1 byte used up in understanding key frame and 4 bytes to determione type of frame
						}
						break;

					case 1://AVC NALU
						{
							m_avcPktState = FLV_DMX_AVC_NALU;
							m_NumBytesExpected = (curSeekPnt.dataSize - 5);
						}
						break;

					case 2: //Frame with no payload
						{
							m_avcPktState = FLV_DMX_AVC_STATE_NO_PAYLOAD;
							m_NumBytesExpected = (curSeekPnt.dataSize - 5);
						}
						break;
				}
			}
			break;

		case FLV_DMX_AVC_DECODER_CONFIG_REC:
			{
				if( DMX_ERR_OK != processConfigRecFrame(inFlvBuf,size,&LengthSize))
				{
					return DMX_ERR_FUNC_FAILED;
				}
			}
			break;

		case FLV_DMX_AVC_NALU:
			{
				if( DMX_ERR_OK != processAVCNALUFrame(inFlvBuf,size,LengthSize))
				{
					return DMX_ERR_FUNC_FAILED;
				}
			}
			break;

		case FLV_DMX_AVC_STATE_NO_PAYLOAD:
			{
				m_state = FLV_DMX_STATE_FLV_TAG_END;
				m_NumBytesExpected = 5;
			}
			break;
	}
	return DMX_ERR_OK;
}

Errtype_e OnFlvTagAudio(unsigned char *inFlvBuf, int size)
{
	printf("-->%s\r\n", __FUNCTION__);
	if(( NULL == inFlvBuf )||( 0 == size ))
	{
		return DMX_ERR_INVALID_PARAM;
	}
	curSeekPnt.decodeTime = getTagTime(inFlvBuf);
	curSeekPnt.dataSize = getDataLen(inFlvBuf);
	curSeekPnt.audDes.soundFmt = ((inFlvBuf[10] & sndCompressMask)>>4);
	curSeekPnt.audDes.soundRate = ((inFlvBuf[10] & sndRateMask) >> 2);
	curSeekPnt.audDes.soundSize = ((inFlvBuf[10] & sndBitMask) >> 1);
	curSeekPnt.audDes.soundType = (inFlvBuf[10] & sndChannelMask);
	if(curSeekPnt.audDes.soundFmt == 10) //AAC Audio data
	{
		ADTS[0] = 0xFF;
		ADTS[1] = 0xF1;
		m_aacPktState = FLV_DMX_AAC_STATE_NONE;
		m_state = FLV_DMX_STATE_A_DATA;
		m_NumBytesExpected = (curSeekPnt.dataSize - 1);
	}
	else
	{
		return DMX_ERR_NON_SUPPORTED_FORMAT;
	}
	return DMX_ERR_OK;
}

Errtype_e prepareADTSheader(unsigned char *tempbuf, int size)
{
	unsigned char audObjectType = 0;
	unsigned char sampFreqIndex = 0;
	unsigned char chnlCfg = 0;
	unsigned char sbr = 0;
	printf("-->%s\r\n", __FUNCTION__);
	if(( NULL == tempbuf )||( 0 == size ))
	{
		return DMX_ERR_INVALID_PARAM;
	}
	audObjectType = ((*tempbuf & AAC_AUD_OBJ_TYPE_MSK)>>3);
	if (audObjectType != 31)
	{
		sampFreqIndex = (*tempbuf & 0x07) <<1 | ((tempbuf[1] & 0x80) >>7);
		chnlCfg = ((tempbuf[1]& 0x78)>>3);
		sbr = 0;
		//fill the ADTS header
		/* syncword; 12 bslbf
		   ID; 1 bslbf
		   layer; 2 uimsbf
		   protection_absent; 1 bslbf
		   profile_ObjectType; 2 uimsbf
		   sampling_frequency_index; 4 uimsbf
		   private_bit; 1 bslbf
		   channel_configuration; 3 uimsbf
		   original_copy; 1 bslbf
		   home;1 bslbf*/

		ADTS[0] =    0xFF;
		ADTS[1] =    0xF1;
		//ID (MPEG4), layer(0), protection_absent (1) are set
		switch(audObjectType)
		{
			case 1:
				{
					ADTS[2] = 0x00; //AAC Main
				}
				break;

			case 2:
			default:
				{
					ADTS[2] = 0x01 <<6; //AAC LC (Low complexity profile
				}
				break;

			case 3:
				{
					ADTS[2] = 0x02<<6; //AAC SSR Scalable Sampling Rate profile
				}
				break;

			case 4:
				{
					ADTS[2] = 0x03<<6; //AAC LTP
				}
				break;			
		}
	}

	if( sampFreqIndex >12 )
	{
		sampFreqIndex = 4; //error and set to default
	}
	ADTS[2] |= (sampFreqIndex & 0x0F) <<2;
	ADTS[2] |= (chnlCfg & 0x7)>>2;
	ADTS[3] = 0x00;
	ADTS[3] |= (chnlCfg & 0x7)<<6;
	return DMX_ERR_OK;
}

Errtype_e OnAudioData(unsigned char *inFlvBuf, int size)
{
	int frameLength = 0;
	unsigned char *temp = NULL;
	int remaining = 0, consumedbytes = 0;

	printf("-->%s\r\n", __FUNCTION__);

	if(( NULL == inFlvBuf )||( 0 == size ))
	{
		return DMX_ERR_INVALID_PARAM;
	}

	remaining = size;
	while( remaining > 0 )
	{
		switch(m_aacPktState)
		{
			case FLV_DMX_AAC_SEQ_HDR:
				{
					if( DMX_ERR_OK != prepareADTSheader((inFlvBuf+1),size-1))
					{
						return DMX_ERR_FUNC_FAILED;
					}
					consumedbytes += remaining;
					m_aacPktState = FLV_DMX_AAC_STATE_NONE;
				}
				break;

			case FLV_DMX_AAC_RAW:
				{
					frameLength = (remaining + 7);
					temp = (unsigned char*)&frameLength;
					ADTS[3] |= ((temp[1] & 0x18) >>3);
					ADTS[4] =  ((temp[1]& 0x07) << 5);
					ADTS[4] |= ((temp[0]& 0xF8) >> 3);
					ADTS[5] =  ((temp[0]&0x07) << 5);
					ADTS[5] |= 0x1F;//buffer fullness is set to FFE.
					ADTS[6] = 0xFC;  //number_of_raw_data_blocks_in_frame (0- 1 bolock)
					SetUnitPTS(curSeekPnt.decodeTime,0);
					fwrite(ADTS,1,7,fpAAC);
					fwrite(&inFlvBuf[size-remaining],1,remaining,fpAAC);
					m_aacPktState = FLV_DMX_AAC_STATE_NONE;
					consumedbytes += remaining;
				}
				break;

			case FLV_DMX_AAC_STATE_NONE:
				{
					m_aacPktState = (inFlvBuf[0] == 1)?FLV_DMX_AAC_RAW:FLV_DMX_AAC_SEQ_HDR;
					consumedbytes += 1;
				}
				break;
		}
		remaining = (size-consumedbytes);
	}
	m_NumBytesExpected = 5;
	m_state = FLV_DMX_STATE_FLV_TAG_END;
	return DMX_ERR_OK;
}

Errtype_e demuxFile(FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned char *tempBuf = NULL;
	unsigned char *origBuf = NULL;
	unsigned int bytesRead = 0;		
	flv_tag dtag;

	printf("-->demuxFile\r\n");
	if( NULL == fp )
	{
		return DMX_ERR_INVALID_PARAM;
	}

	while(1)
	{
		printf("-->m_NumBytesExpected:m_state %d: %d - %s\r\n", m_NumBytesExpected, m_state, state2str[m_state].state_string);
		if( m_NumBytesExpected <= MAX_STACK_BUFF )
		{
			tempBuf = buff;
		}
		else
		{
			printf("-->Allocating %d bytes of memory to ready tag\r\n", m_NumBytesExpected);
			tempBuf = (unsigned char *)malloc(m_NumBytesExpected * sizeof(unsigned char));
			if( NULL == tempBuf )
			{
				return DMX_ERR_FUNC_FAILED;
			}
			else
			{
				origBuf = tempBuf;
			}
		}
		printf("-->Reading %d bytes form file\r\n", m_NumBytesExpected);

		bytesRead = fread(tempBuf, sizeof(unsigned char), m_NumBytesExpected, fp);

		if(( m_NumBytesExpected != bytesRead )||( 0 == m_NumBytesExpected))
		{
			printf("Reached end of file\r\n");
			break;
		}

		switch(m_state)
		{
			case FLV_DMX_STATE_FLV_HDR:
			case FLV_DMX_STATE_FLV_TAG_END:
				{
					if( DMX_ERR_OK != beginNewTag(tempBuf, bytesRead))
					{
						return DMX_ERR_FUNC_FAILED;
					}
				}
				break;

			case FLV_DMX_STATE_TAG_D:
				{
					if( DMX_ERR_OK != OnFlvTagData(tempBuf,bytesRead))
					{
						return DMX_ERR_FUNC_FAILED;
					}
				}
				break;

			case FLV_DMX_STATE_FLV_TAG_META_DATA:
				{
					if( DMX_ERR_OK != getMetadataInfo(tempBuf,bytesRead))
					{
						return DMX_ERR_FUNC_FAILED;
					}
				}
				break;

			case FLV_DMX_STATE_TAG_V:
				{
					printf("-->reading FLV_DMX_STATE_TAG_V\r\n");
					if( DMX_ERR_OK != OnFlvTagVideo(tempBuf,bytesRead))
					{
						return DMX_ERR_FUNC_FAILED;
					}
				}
				break;

			case FLV_DMX_STATE_V_DATA:
				{
					if( DMX_ERR_OK != OnVideoData(tempBuf,bytesRead))
					{
						return DMX_ERR_FUNC_FAILED;
					}
				}
				break;

			case FLV_DMX_STATE_TAG_A:
				{
					if( DMX_ERR_OK != OnFlvTagAudio(tempBuf,bytesRead))
					{
						return DMX_ERR_FUNC_FAILED;
					}
				}
				break;

			case FLV_DMX_STATE_A_DATA:
				{
					if( DMX_ERR_OK != OnAudioData(tempBuf,bytesRead))
					{
						return DMX_ERR_FUNC_FAILED;
					}
				}
				break;

			default:
				{
					printf("Shoudn't ever come here\r\n");
					return DMX_ERR_FUNC_FAILED;
				}
				break;

		}
	}
	if( NULL != origBuf )
	{
		free(origBuf);
		origBuf = NULL;
	}
	return DMX_ERR_OK;
}

int main()
{
	uint32 a;
	FILE *fp = fopen(INPUT_FILE_PATH,"rb");
	fpH264 = fopen(OUTPUT_VIDEO_ES_PATH, "wb");
	fpAAC = fopen(OUTPUT_AUDIO_ES_PATH, "wb");
	fpDTS = fopen(OUTPUT_DTS_PATH, "w");

	if(( NULL == fp )||( NULL == fpH264)||(NULL == fpAAC)||(NULL == fpDTS))
	{
		printf("Failed to open the file\r\n");
	}
	else
	{		
		if( DMX_ERR_OK == initiateflvdemux(fp))
		{
			demuxFile(fp);
		}		
		fclose(fp);
		fclose(fpH264);
		fclose(fpAAC);
		fclose(fpDTS);
	}
	return 0;
}
