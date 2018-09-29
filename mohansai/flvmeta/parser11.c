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

FILE *fpH264 = NULL;
FILE *fpAAC = NULL;
FILE *fpDTS = NULL;
/*
int read_from_file(char *buff, FILE *fp)
{

}
*/
int print_flv_file_header(flv_header *pheader)
{
	printf("signature :%c%c%c\r\n", pheader->signature[0], pheader->signature[1], pheader->signature[2]);
	printf("version   :%d\r\n", pheader->version);
	printf("flags     :%d\r\n", pheader->flags);
	printf("offset    :%x\r\n", pheader->offset);
printf("\n\n");
	return 0;
}

int populate_flv_file_header(flv_header *pheader, unsigned char *pdestBuf)
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

int read_flv_header(FILE *fp) /* flv header reading */
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

	return 0;
}

int populate_flv_file_tag(flv_tag *ptag, unsigned char *pdestBuf)
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

#if 0
	ptag->timestamp_extended = pdestBuf[11];

	((unsigned char *)&ptag-> stream_id)[0] = pdestBuf[15];
	((unsigned char *)&ptag-> stream_id)[1] = pdestBuf[14];
	((unsigned char *)&ptag-> stream_id)[2] = pdestBuf[13];
	((unsigned char *)&ptag-> stream_id)[3] = pdestBuf[12];
#endif

	return 0;

}

int  print_flv_file_tag(flv_tag *ptag)
{
	printf("-->previoustag        :%d\r\n", ptag->previous_tag_size); 
	printf("-->type               :%d\r\n", ptag->type); 
	printf("-->dataSize           :%d\r\n", ptag->body_length); 
	printf("-->offset             :%d\r\n", 0x0); 
	printf("-->time_stamp         :%d\r\n", ptag-> timestamp); 
	//	printf("-->timestamp_extended :%d\r\n", ptag->timestamp_extended); 
	//	printf("--> stream_id         :%d\r\n", ptag-> stream_id); 
	printf("\n\n");
	
printf("");
	return 0; 

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


Errtype_e MV_getFileDuration(unsigned char *buf, int size )
{
	unsigned char *durPtr = buf;
	unsigned char arr[10] = "\0";
	int counter = 0;
	//double *num = NULL;
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


Errtype_e getMetadataInfo(unsigned char *buf, int size)
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

int read_metadata(flv_tag *ptag, FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		

	bytesRead = fread(buff, sizeof(unsigned char), ptag->body_length, fp);

	printf("-->bytesRead  	:%d\r\n", bytesRead);

	getMetadataInfo(buff, bytesRead);

	return bytesRead;
}


int read_tag_header(FILE *fp)
{
	flv_tag tag;
	unsigned char destBuf[124];

	if (fread(destBuf, sizeof(unsigned char), 15 , fp) < 0)
	{
		perror ("Read failed");
		exit(1);
	}

	populate_flv_file_tag(&tag, destBuf);
	print_flv_file_tag(&tag);
	read_metadata(&tag, fp);

	return 0;
}

int video_tag(int body_length,FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		
	unsigned char temp = 0;
	bytesRead = fread(buff, sizeof(unsigned char), body_length, fp);
	//printf("-->video byetsRead  :%d\r\n",  bytesRead);
	temp = buff[0] & 0x0f;
	printf("-->byte value :%d\r\n", temp);
	if(temp == 2)
		printf("-->codecID: Sorensen H.263\r\n");
	else if(temp == 3)
		printf("-->codecID: Screen video\r\n");
	else if(temp == 4)
		printf("-->codecID: On2 VP6\r\n");
	else if(temp == 5)
		printf("-->codecID: On2 VP6 with alpha channel\r\n");
	else if(temp == 6)
		printf("-->codecID: Screen video version 2\r\n");
	else if(temp == 7)
		printf("-->codecID: AVC\r\n");
	else 
		printf("-->codecID: UnKnown\r\n");

	temp = buff[0] & 0xf0;
	printf("-->byte value :%d\r\n", temp);
	if(temp == 1)
		printf("-->FrameType: KeyFrame\r\n");
	else if(temp == 2)
		printf("-->FrameType: InnerFrame\r\n");
	else if(temp == 3)
		printf("-->FrameType: Disposible innerframe\r\n");
	else
		printf("-->FrameType: Unknown\r\n");
	//exit(0);
	return 0;
}

static int audio_tag(int body_length, FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		
	//unsigned char a;
	//char *p;
	int temp = 0;
	bytesRead = fread(buff, sizeof(unsigned char), body_length, fp);
	//printf("-->audio byetsRead: %d\r\n",  bytesRead);
	if(buff[0] & 0x01)
		printf("-->audioData type :Stereo\r\n");
	else
		printf("-->audioData type :Mono\r\n");

	if(buff[0] & 0x02)
		printf("-->size :16-bit\r\n");
	else
		printf("-->size :8-bit\r\n");

	temp = buff[0] & 0x0C;
	if(temp == 0)
		printf("-->rate :5.5KHz\r\n");
	else if(temp == 1)
		printf("-->rate :11KHz\r\n");
	else if(temp == 2)
		printf("-->rate :22KHz\r\n");
	else 
		printf("-->rate :44KHz\r\n");

	temp = buff[0] & 0xf0;
	if(temp == 0)
		printf("-->format :Uncompressed\r\n");
	else if(temp == 1)
		printf("-->format :ADPCM\r\n");
	else if(temp == 2)
		printf("-->format :MP3\r\n");
	else if(temp == 5)
		printf("-->format :Nellymoser 8KHz mono\r\n");
	else
		printf("-->format :Nellymoser\r\n");

	return 0;
}



static int read_audio_video_tag(FILE *fp)
{
	//flv_tag tag;
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	//unsigned int bytesRead = 0;		
	unsigned int prev_tagsize;
	unsigned char type;
	unsigned int bodylength;
	unsigned int timestamp;
	int count=0;
	while(ftell(fp)!=EOF)
	{
		if(count++==5)
			break;

		fread(buff, sizeof(unsigned char), 15, fp); 

		((unsigned char *)&prev_tagsize)[0] = buff[3];
		((unsigned char *)&prev_tagsize)[1] = buff[2];
		((unsigned char *)&prev_tagsize)[2] = buff[1];
		((unsigned char *)&prev_tagsize)[3] = buff[0];

		type = buff[4];

		((unsigned char *)&bodylength)[0] = buff[7];
		((unsigned char *)&bodylength)[1] = buff[6];
		((unsigned char *)&bodylength)[2] = buff[5];
		((unsigned char *)&bodylength)[3] = 0;

		((unsigned char *)&timestamp)[0] = buff[10];
		((unsigned char *)&timestamp)[1] = buff[9];
		((unsigned char *)&timestamp)[2] = buff[8];
		((unsigned char *)&timestamp)[3] = 0;

		printf("-->prev_tagsize :%d\r\n", prev_tagsize);
		printf("-->type         :%d\r\n", type);
		printf("-->time_stamp   :%d\r\n", timestamp); 
		printf("-->dataSize     :%d\r\n", bodylength); 
		printf("-->offset       :%d\r\n", 0x0); 

		if(type==8)
		{
			//printf(" body_length %d", bodylength );
			audio_tag(bodylength,fp);
		}
		else
		{
			if(type==9)			
			{
				//printf(" body_length %d", bodylength );
				video_tag(bodylength,fp);
			}
		}		
		printf("-------------------------------------------------\r\n");

	}
	return 0;
}

int main()
{
	//uint32 a;
	FILE *fp = fopen(INPUT_FILE_PATH, "rb");
	fpH264 = fopen(OUTPUT_VIDEO_ES_PATH, "wb");
	fpAAC = fopen(OUTPUT_AUDIO_ES_PATH, "wb");
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
	return 0;
}

