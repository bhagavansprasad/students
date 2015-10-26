#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "inttypes.h"
#include "types.h"
#include "stdint.h"
#include "sys/types.h"
#include "flvdemux.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"

/*  audio tag */
#define FLV_AUDIO_TAG_SOUND_TYPE_MONO    0
#define FLV_AUDIO_TAG_SOUND_TYPE_STEREO  1

#define FLV_AUDIO_TAG_SOUND_SIZE_8       0
#define FLV_AUDIO_TAG_SOUND_SIZE_16      1

#define FLV_AUDIO_TAG_SOUND_RATE_5_5     0
#define FLV_AUDIO_TAG_SOUND_RATE_11      1
#define FLV_AUDIO_TAG_SOUND_RATE_22      2
#define FLV_AUDIO_TAG_SOUND_RATE_44      3

#define FLV_AUDIO_TAG_SOUND_FORMAT_LINEAR_PCM          0
#define FLV_AUDIO_TAG_SOUND_FORMAT_ADPCM               1
#define FLV_AUDIO_TAG_SOUND_FORMAT_MP3                 2
#define FLV_AUDIO_TAG_SOUND_FORMAT_LINEAR_PCM_LE       3
#define FLV_AUDIO_TAG_SOUND_FORMAT_NELLYMOSER_16_MONO  4
#define FLV_AUDIO_TAG_SOUND_FORMAT_NELLYMOSER_8_MONO   5
#define FLV_AUDIO_TAG_SOUND_FORMAT_NELLYMOSER          6
#define FLV_AUDIO_TAG_SOUND_FORMAT_G711_A              7
#define FLV_AUDIO_TAG_SOUND_FORMAT_G711_MU             8
#define FLV_AUDIO_TAG_SOUND_FORMAT_RESERVED            9
#define FLV_AUDIO_TAG_SOUND_FORMAT_AAC                 10
#define FLV_AUDIO_TAG_SOUND_FORMAT_SPEEX               11
#define FLV_AUDIO_TAG_SOUND_FORMAT_MP3_8               14
#define FLV_AUDIO_TAG_SOUND_FORMAT_DEVICE_SPECIFIC     15

/* video tag */
#define FLV_VIDEO_TAG_CODEC_JPEG            1
#define FLV_VIDEO_TAG_CODEC_SORENSEN_H263   2
#define FLV_VIDEO_TAG_CODEC_SCREEN_VIDEO    3
#define FLV_VIDEO_TAG_CODEC_ON2_VP6         4
#define FLV_VIDEO_TAG_CODEC_ON2_VP6_ALPHA   5
#define FLV_VIDEO_TAG_CODEC_SCREEN_VIDEO_V2 6
#define FLV_VIDEO_TAG_CODEC_AVC             7

#define FLV_VIDEO_TAG_FRAME_TYPE_KEYFRAME               1
#define FLV_VIDEO_TAG_FRAME_TYPE_INTERFRAME             2
#define FLV_VIDEO_TAG_FRAME_TYPE_DISPOSABLE_INTERFRAME  3
#define FLV_VIDEO_TAG_FRAME_TYPE_GENERATED_KEYFRAME     4
#define FLV_VIDEO_TAG_FRAME_TYPE_COMMAND_FRAME          5


FILE *fpH264 = NULL;
FILE *fpAAC = NULL;
FILE *fpDTS = NULL;
//FILE *fptags = NULL;

int  metadata_tag_size=0;

static int print_flv_file_header(flv_header *pheader)
{
	printf("signature :%c%c%c\r\n", pheader->signature[0], pheader->signature[1], pheader->signature[2]);
	printf("version   :%d\r\n", pheader->version);
	printf("flags     :%d\r\n", pheader->flags);
	printf("offset    :%x\r\n", pheader->offset);
	printf("\n\n");
	return 0;
}

static int populate_flv_file_header(flv_header *pheader, unsigned char *pdestBuf)
{
	pheader->signature[0] = pdestBuf[0];
	pheader->signature[1] = pdestBuf[1];
	pheader->signature[2] = pdestBuf[2];

	pheader->version = pdestBuf[3];

	pheader->flags = pdestBuf[4];

	((unsigned char *)&pheader->offset)[0] = pdestBuf[8];
	((unsigned char *)&pheader->offset)[1] = pdestBuf[7];
	((unsigned char *)&pheader->offset)[2] = pdestBuf[6];
	((unsigned char *)&pheader->offset)[3] = pdestBuf[5];

	return 0;
}

static int read_flv_header(FILE *fp) /* flv header reading */
{
	flv_header header;
	unsigned char destBuf[64];
	unsigned char readBytes = 0;

	if (readBytes = fread(destBuf, sizeof(unsigned char), 9, fp) < 0)
	{
		perror("Read failed");
		exit(1);
	}

	populate_flv_file_header(&header, destBuf);
	print_flv_file_header(&header);

	destBuf[4] = 1;
	fwrite(destBuf, sizeof(unsigned char), 9, fpH264);

	destBuf[4] = 4;
	fwrite(destBuf, sizeof(unsigned char), 9, fpAAC);

	return 0;
}

static int populate_flv_file_tag(flv_tag *ptag, unsigned char *pdestBuf)
{
	((unsigned char *)&ptag->previous_tag_size)[0] = pdestBuf[0];
	((unsigned char *)&ptag->previous_tag_size)[1] = pdestBuf[1];
	((unsigned char *)&ptag->previous_tag_size)[2] = pdestBuf[2];
	((unsigned char *)&ptag->previous_tag_size)[3] = pdestBuf[3];

	ptag-> type = pdestBuf[4];

	((unsigned char *)&ptag->body_length)[0] = pdestBuf[7];
	((unsigned char *)&ptag->body_length)[1] = pdestBuf[6];
	((unsigned char *)&ptag->body_length)[2] = pdestBuf[5];
	((unsigned char *)&ptag->body_length)[3] = 0;

	((unsigned char *)&ptag->timestamp)[0] = pdestBuf[10];
	((unsigned char *)&ptag->timestamp)[1] = pdestBuf[9];
	((unsigned char *)&ptag->timestamp)[2] = pdestBuf[8];
	((unsigned char *)&ptag->timestamp)[3] = 0;

	metadata_tag_size=ptag->body_length+11;
#if 0
	ptag->timestamp_extended = pdestBuf[11];
	((unsigned char *)&ptag-> stream_id)[0] = pdestBuf[15];
	((unsigned char *)&ptag-> stream_id)[1] = pdestBuf[14];
	((unsigned char *)&ptag-> stream_id)[2] = pdestBuf[13];
	((unsigned char *)&ptag-> stream_id)[3] = pdestBuf[12];
#endif
	
	return 0;

}

static int print_flv_file_tag(flv_tag *ptag)
{
	printf("-->previoustag        :%d\r\n", ptag->previous_tag_size); 
	printf("-->type               :%d\r\n", ptag->type); 
	printf("-->dataSize           :%d\r\n", ptag->body_length); 
	printf("-->offset             :%d\r\n", 0x0); 
	printf("-->time_stamp         :%d\r\n", ptag-> timestamp); 
	//	printf("-->timestamp_extended :%d\r\n", ptag->timestamp_extended); 
	//	printf("--> stream_id         :%d\r\n", ptag-> stream_id); 
	printf("\n\n");
	return 0; 
}

static unsigned int getUnsigned(unsigned char *buff, int size)
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

static int flvScrGetString(unsigned char *instrBuf, char *outstrBuf)
{
	unsigned short length = getUnsigned(instrBuf, 2);
	int i =0;
	printf("-->%s\r\n", __FUNCTION__);
	if(length >254)
	{
		return -1;
	}

	for(i =0;i<length;i++)
	{
		outstrBuf[i] = instrBuf[i+2];
	}
	outstrBuf[length] = '\0';
	return length+2;
}

static unsigned char* getString(unsigned char *buff)
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


static Errtype_e MV_getFileDuration(unsigned char *buf, int size )
{
	unsigned char *durPtr = buf;
	unsigned char arr[10] = "\0";
	int counter = 0;
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


static Errtype_e getMetadataInfo(unsigned char *buf, int size)
{
	char str[256];
	int count=0;
	int length=0;
	if(buf[count++]==2);
	{
		length = flvScrGetString(&buf[1], str);
		count = (count + length);	
		if(0==strcmp(str, "onMetaData"))
		{
			buf = buf + count;
			MV_getFileDuration(buf,(size-size));
		}
		printf("-->str 	:%s\n\r",str);
		printf("\n\r");
	}

	return 0;
}

static int read_metadata(flv_tag *ptag, FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		

	bytesRead = fread(buff, sizeof(unsigned char), ptag->body_length, fp);

	fwrite(buff, sizeof(unsigned char),ptag->body_length , fpH264);
	fwrite(buff, sizeof(unsigned char),ptag->body_length , fpAAC);
	getMetadataInfo(buff, bytesRead);

	return bytesRead;
}

static int read_tag_header(FILE *fp)
{
	flv_tag tag;
	unsigned char destBuf[124];

	if (fread(destBuf, sizeof(unsigned char), 15 , fp) < 0)
	{
		perror ("Read failed");
		exit(1);
	}

	fwrite(destBuf, sizeof(unsigned char), 15, fpH264);
	fwrite(destBuf, sizeof(unsigned char), 15, fpAAC);
	populate_flv_file_tag(&tag, destBuf);
	print_flv_file_tag(&tag);
	read_metadata(&tag, fp);

	return 0;
}

const char * video_codec(int temp) 
{
	switch (temp) 
	{
		case FLV_VIDEO_TAG_CODEC_JPEG: return "JPEG";
		case FLV_VIDEO_TAG_CODEC_SORENSEN_H263: return "Sorenson H.263";
		case FLV_VIDEO_TAG_CODEC_SCREEN_VIDEO: return "Screen video";
		case FLV_VIDEO_TAG_CODEC_ON2_VP6: return "On2 VP6";
		case FLV_VIDEO_TAG_CODEC_ON2_VP6_ALPHA: return "On2 VP6 with alpha channel";
		case FLV_VIDEO_TAG_CODEC_SCREEN_VIDEO_V2: return "Screen video version 2";
		case FLV_VIDEO_TAG_CODEC_AVC: return "AVC";
		default: return "Unknown";
	}
}

const char * video_frame_type(int temp) 
{
	switch (temp) 
	{
		case FLV_VIDEO_TAG_FRAME_TYPE_KEYFRAME: return "keyframe";
		case FLV_VIDEO_TAG_FRAME_TYPE_INTERFRAME: return "inter frame";
		case FLV_VIDEO_TAG_FRAME_TYPE_DISPOSABLE_INTERFRAME: return "disposable inter frame";
		case FLV_VIDEO_TAG_FRAME_TYPE_GENERATED_KEYFRAME: return "generated keyframe";
		case FLV_VIDEO_TAG_FRAME_TYPE_COMMAND_FRAME: return "video info/command frame";
		default: return "Unknown";
	}
}

const char * sound_type(int temp) 
{
	switch (temp) 
	{
		case FLV_AUDIO_TAG_SOUND_TYPE_MONO: return "mono";
		case FLV_AUDIO_TAG_SOUND_TYPE_STEREO: return "stereo";
		default: return "Unknown";
	}
}

const char * sound_size(int temp) 
{
	switch (temp) 
	{
		case FLV_AUDIO_TAG_SOUND_SIZE_8: return "8";
		case FLV_AUDIO_TAG_SOUND_SIZE_16: return "16";
		default: return "Unknown";
	}
}

const char * sound_rate(int temp) 
{
	switch (temp) 
	{
		case FLV_AUDIO_TAG_SOUND_RATE_5_5: return "5.5";
		case FLV_AUDIO_TAG_SOUND_RATE_11: return "11";
		case FLV_AUDIO_TAG_SOUND_RATE_22: return "22";
		case FLV_AUDIO_TAG_SOUND_RATE_44: return "44";
		default: return "Unknown";
	}
}

const char * sound_format(int temp) 
{
	switch (temp) 
	{
		case FLV_AUDIO_TAG_SOUND_FORMAT_LINEAR_PCM: return "Linear PCM, platform endian";
		case FLV_AUDIO_TAG_SOUND_FORMAT_ADPCM: return "ADPCM";
		case FLV_AUDIO_TAG_SOUND_FORMAT_MP3: return "MP3";
		case FLV_AUDIO_TAG_SOUND_FORMAT_LINEAR_PCM_LE: return "Linear PCM, little-endian";
		case FLV_AUDIO_TAG_SOUND_FORMAT_NELLYMOSER_16_MONO: return "Nellymoser 16-kHz mono";
		case FLV_AUDIO_TAG_SOUND_FORMAT_NELLYMOSER_8_MONO: return "Nellymoser 8-kHz mono";
		case FLV_AUDIO_TAG_SOUND_FORMAT_NELLYMOSER: return "Nellymoser";
		case FLV_AUDIO_TAG_SOUND_FORMAT_G711_A: return "G.711 A-law logarithmic PCM";
		case FLV_AUDIO_TAG_SOUND_FORMAT_G711_MU: return "G.711 mu-law logarithmic PCM";
		case FLV_AUDIO_TAG_SOUND_FORMAT_RESERVED: return "reserved";
		case FLV_AUDIO_TAG_SOUND_FORMAT_AAC: return "AAC";
		case FLV_AUDIO_TAG_SOUND_FORMAT_SPEEX: return "Speex";
		case FLV_AUDIO_TAG_SOUND_FORMAT_MP3_8: return "MP3 8-Khz";
		case FLV_AUDIO_TAG_SOUND_FORMAT_DEVICE_SPECIFIC: return "Device-specific sound";
		default: return "Unknown";
	}
}

static int video_tag(int body_length, FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		
	unsigned char temp = 0;
	bytesRead = fread(buff, sizeof(unsigned char), body_length, fp);

	printf("    <videoData codecID=\"%s\" frameType=\"%s\"/>\r\n", 
			video_codec( (buff[0] & 0x0f )),
			video_frame_type((buff[0] >> 4)&0x0f));

	fwrite(buff, sizeof(unsigned char), body_length, fpH264 );

	return 0;
}

static int audio_tag(int body_length, FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		

	bytesRead = fread(buff, sizeof(unsigned char), body_length, fp);

	printf("    <audioData type=\"%s\" size=\"%s\" rate=\"%s\" format=\"%s\"/>\r\n", 
			sound_type((buff[0] & 0x01) >> 0),
			sound_size((buff[0] & 0x02) >> 1 ), 
			sound_rate((buff[0] & 0x0C) >> 2), 
			sound_format((buff[0] & 0xF0) >> 4));

	fwrite(buff, sizeof(unsigned char),body_length , fpAAC);

	return 0;
}

static int read_audio_video_tag(FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned char audio_buff[MAX_STACK_BUFF];
	unsigned char video_buff[MAX_STACK_BUFF];
	unsigned char type;
	unsigned int bodylength,timestamp, prev_tagsize;
	int count = 0,temp = 0;
	int i=1,x=0;
	while(1)
	{  
		int nob = 0;	
		nob = fread(buff, sizeof(unsigned char), 15, fp); 

		type=buff[4];
		if(type == 8)
		{

			if(x==0)
			{

				if(count==0)
					count++;
				else 		
				{

					buff[0]=0;
					buff[1]=audio_buff[5];
					buff[2]=audio_buff[6];
					buff[3]=audio_buff[7];
				}



				((unsigned char *)&prev_tagsize)[0] = buff[3];
				((unsigned char *)&prev_tagsize)[1] = buff[2];
				((unsigned char *)&prev_tagsize)[2] = buff[1];
				((unsigned char *)&prev_tagsize)[3] = buff[0];

				((unsigned char *)&bodylength)[0] = buff[7];
				((unsigned char *)&bodylength)[1] = buff[6];
				((unsigned char *)&bodylength)[2] = buff[5];
				((unsigned char *)&bodylength)[3] = 0;

				((unsigned char *)&timestamp)[0] = buff[10];
				((unsigned char *)&timestamp)[1] = buff[9];
				((unsigned char *)&timestamp)[2] = buff[8];
				((unsigned char *)&timestamp)[3] = 0;

				//	if(i==1)
				//	   i++;
				//	else
				//   	prev_tagsize=prev_tagsize+11;

				buff[3]=    ((unsigned char *)&metadata_tag_size)[0];
				buff[2]=	((unsigned char *)&metadata_tag_size)[1];
				buff[1]=	((unsigned char *)&metadata_tag_size)[2];
				buff[0]=	((unsigned char *)&metadata_tag_size)[3];

				printf("<tagprev_tagsize \"%d\" type=\"audio\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%ld\">\r\n",
						metadata_tag_size,timestamp, bodylength,(ftell(fp)-11) );

				fwrite(buff, sizeof(unsigned char), 15, fpAAC);
				memcpy(audio_buff, buff, 25);
				audio_tag(bodylength,fp);
				printf("  </tag>\r\n");
				x++;
			}
			else
			{
				if(count==0)
					count++;
				else 		
				{
					buff[0]=0;
					buff[1]=audio_buff[5];
					buff[2]=audio_buff[6];
					buff[3]=audio_buff[7];
				}

				((unsigned char *)&prev_tagsize)[0] = buff[3];
				((unsigned char *)&prev_tagsize)[1] = buff[2];
				((unsigned char *)&prev_tagsize)[2] = buff[1];
				((unsigned char *)&prev_tagsize)[3] = buff[0];

				((unsigned char *)&bodylength)[0] = buff[7];
				((unsigned char *)&bodylength)[1] = buff[6];
				((unsigned char *)&bodylength)[2] = buff[5];
				((unsigned char *)&bodylength)[3] = 0;

				((unsigned char *)&timestamp)[0] = buff[10];
				((unsigned char *)&timestamp)[1] = buff[9];
				((unsigned char *)&timestamp)[2] = buff[8];
				((unsigned char *)&timestamp)[3] = 0;

				if(i==1)
					i++;
				else
					prev_tagsize=prev_tagsize+11;

				buff[3]=  ((unsigned char *)&prev_tagsize)[0];
				buff[2]=	((unsigned char *)&prev_tagsize)[1];
				buff[1]=	((unsigned char *)&prev_tagsize)[2];
				buff[0]=	((unsigned char *)&prev_tagsize)[3];

				printf("<tagprev_tagsize \"%d\" type=\"audio\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%ld\">\r\n",
						prev_tagsize,timestamp, bodylength,(ftell(fp)-11) );

				fwrite(buff, sizeof(unsigned char), 15, fpAAC);
				memcpy(audio_buff, buff, 25);
				audio_tag(bodylength,fp);
				printf("  </tag>\r\n");

			}
		}
		else if(type==9)
		{
			if(temp==0)
				temp++;
			else
			{
				buff[0]=0;
				buff[1]=video_buff[5];
				buff[2]=video_buff[6];
				buff[3]=video_buff[7];
			}
			((unsigned char *)&prev_tagsize)[0] = buff[3];
			((unsigned char *)&prev_tagsize)[1] = buff[2];
			((unsigned char *)&prev_tagsize)[2] = buff[1];
			((unsigned char *)&prev_tagsize)[3] = buff[0];

			((unsigned char *)&bodylength)[0] = buff[7];
			((unsigned char *)&bodylength)[1] = buff[6];
			((unsigned char *)&bodylength)[2] = buff[5];
			((unsigned char *)&bodylength)[3] = 0;

			((unsigned char *)&timestamp)[0] = buff[10];
			((unsigned char *)&timestamp)[1] = buff[9];
			((unsigned char *)&timestamp)[2] = buff[8];
			((unsigned char *)&timestamp)[3] = 0;
			if(i==1)
				i++;
			else
				prev_tagsize=prev_tagsize+11;

			//	prev_tagsize=prev_tagsize+11;
			buff[3]=  ((unsigned char *)&prev_tagsize)[0];
			buff[2]=	((unsigned char *)&prev_tagsize)[1];
			buff[1]=	((unsigned char *)&prev_tagsize)[2];
			buff[0]=	((unsigned char *)&prev_tagsize)[3];

			printf("<tagprev_tagsize \"%d\" type=\"video\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%ld\">\r\n",
					prev_tagsize,timestamp, bodylength,(ftell(fp)-11) );

			fwrite(buff, sizeof(unsigned char), 15, fpH264);
			memcpy(video_buff, buff, 25);
			video_tag(bodylength,fp);
			printf("  </tag>\r\n");
		}		

		if(nob < 15)
		{
			printf("\t\t\t------------file ended----------\r\n");
			break;
		}
	}
	return 0;
}

int main()
{
	FILE *fp = fopen(INPUT_FILE_PATH, "rb");
	fpH264 = fopen(OUTPUT_VIDEO_ES_PATH, "wb");
	fpAAC = fopen("audio.flv", "wb");
	fpDTS = fopen(OUTPUT_DTS_PATH, "w");

	if(( NULL == fp )||( NULL == fpH264)||(NULL == fpAAC)||(NULL == fpDTS))
	{
		printf("Failed to open the file\r\n");
		exit(1);
	}

	read_flv_header(fp);
	read_tag_header(fp);
	read_audio_video_tag(fp);

	fclose(fp);
	fclose(fpH264);
	fclose(fpAAC);
	fclose(fpDTS);
	//fclose(fptags);

	return 0;
}
