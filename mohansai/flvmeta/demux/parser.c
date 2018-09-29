#include <stdio.h>
#include <string.h>
#include "inttypes.h"
#include "stdlib.h"
#include "types.h"
#include "flvdemux.h"

//#define XML_PRINT 1

tag_data  gtag_data;
tag_data *head;

/*  audio tag */

FILE *fpH264 = NULL;
FILE *fpAAC = NULL;
FILE *fpDTS = NULL;
FILE *fptags = NULL;

static int print_flv_file_header(flv_header *pheader)
{
	printf("signature :%c%c%c\n", pheader->signature[0], pheader->signature[1], pheader->signature[2]);
	printf("version   :%d\n", pheader->version);
	printf("flags     :%d\n", pheader->flags);
	printf("offset    :%x\n", pheader->offset);
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

	// fwrite(destBuf, sizeof(unsigned char), 9, fpH264);
	// fwrite(destBuf, sizeof(unsigned char), 9, fpAAC);
	populate_flv_file_header(&header, destBuf);
	print_flv_file_header(&header);

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
	printf("-->previoustag        :%d\n", ptag->previous_tag_size); 
	printf("-->type               :%d\n", ptag->type); 
	printf("-->dataSize           :%d\n", ptag->body_length); 
	printf("-->offset             :%d\n", 0x0); 
	printf("-->time_stamp         :%d\n", ptag-> timestamp); 
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
	printf("-->%s\n", __FUNCTION__);
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
	printf("-->%s\n", __FUNCTION__);
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
	printf("-->%s\n", __FUNCTION__);

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
			printf("Duration is %2.1f\n",duration);
		}
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
		printf("-->str 	:%s\n",str);
		printf("\n");
	}

	return 0;
}

static int read_metadata(flv_tag *ptag, FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		

	bytesRead = fread(buff, sizeof(unsigned char), ptag->body_length, fp);

	//fwrite(buff, sizeof(unsigned char),ptag->body_length , fpH264);
	//fwrite(buff, sizeof(unsigned char),ptag->body_length , fpAAC);
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

	//fwrite(destBuf, sizeof(unsigned char), 15, fpH264);
	//fwrite(destBuf, sizeof(unsigned char), 15, fpAAC);
	populate_flv_file_tag(&tag, destBuf);
	print_flv_file_tag(&tag);
	read_metadata(&tag, fp);

	return 0;
}

const char * video_codec(int temp) 
{
	switch (temp) 
	{

		case 2 : strcpy(gtag_data.c_codec_ID, "Sorenson H.263");break; 
		case 3 : strcpy(gtag_data.c_codec_ID, "Screen video");break; 
		case 4 : strcpy(gtag_data.c_codec_ID, "On2 VP6"); break; 
		case 5 : strcpy(gtag_data.c_codec_ID, "On2 VP6 with alpha channelo");break; 
		case 6 : strcpy(gtag_data.c_codec_ID, "Screen video version 2");break; 
		case 7 : strcpy(gtag_data.c_codec_ID, "AVC"); break; 
		default: return "Unknown";break; 
	}
}

const char * video_frame_type(int temp) 
{
	switch (temp) 
	{
		case 1 : strcpy(gtag_data.c_frame_type,"keyframe");	 break;
		case 2 : strcpy(gtag_data.c_frame_type,"inter frame"); break;
		case 3 : strcpy(gtag_data.c_frame_type,"disposableframe"); break;
		case 4 : strcpy(gtag_data.c_frame_type,"generated keyframe"); break;
		case 5 : strcpy(gtag_data.c_frame_type,"video info frame"); break;
		default: return "Unknown";
	}
}

const char * sound_type(int temp) 
{
	switch (temp) 
	{
		case 0 : strcpy(gtag_data.c_sound_type,"Mono sound"); break; 
		case 1 : strcpy(gtag_data.c_sound_type,"stereo");break;
		default: return "Unknown";
	}
}

const char * sound_size(int temp) 
{
	switch (temp) 
	{
		case 0: strcpy(gtag_data.c_sound_size,"8" ); break; 
		case 1: strcpy(gtag_data.c_sound_size,"16"); break; 
		default: return "Unknown";
	}
}

const char * sound_rate(int temp) 
{
	switch (temp) 
	{
		case 0 : strcpy(gtag_data.c_sound_rate,"55");break; 
		case 1 : strcpy(gtag_data.c_sound_rate,"11");break; 
		case 2 : strcpy(gtag_data.c_sound_rate,"22");break; 
		case 3 : strcpy(gtag_data.c_sound_rate,"44");break; 
		default: return "Unknown";
	}
}

const char * sound_format(int temp) 
{
	switch (temp) 
	{
		case 0  : strcpy(gtag_data.c_sound_format,"Linear PCM, platform endian");break; 
		case 1  : strcpy(gtag_data.c_sound_format,"ADPCM");break; 
		case 2  : strcpy(gtag_data.c_sound_format,"MP3");break; 
		case 3  : strcpy(gtag_data.c_sound_format,"Linear PCM, little-endian");break; 
		case 4  : strcpy(gtag_data.c_sound_format,"Nellymoser 16-kHz mono");break; 
		case 5  : strcpy(gtag_data.c_sound_format,"Nellymoser 8-kHz mono");break; 
		case 6  : strcpy(gtag_data.c_sound_format,"Nellymoser");break; 
		case 7  : strcpy(gtag_data.c_sound_format,"G.711 A-law logarithmic PCM");break; 
		case 8  : strcpy(gtag_data.c_sound_format,"G.711 mu-law logarithmic PCM");break; 
		case 9 : strcpy(gtag_data.c_sound_format,"reserved");break; 
		case 10 : strcpy(gtag_data.c_sound_format,"AAC"); break; 
		case 11 : strcpy(gtag_data.c_sound_format,"Speex");break; 
		case 14 : strcpy(gtag_data.c_sound_format,"MP3 8-Khz");break; 
		case 15 : strcpy(gtag_data.c_sound_format,"Device-specific sound");break; 
		default: return "Unknown";break; 
	}
}
void displaylist()

{
	tag_data *temp;
	int i=0;
	for(temp = head ; temp != NULL ; temp = temp->next)
	{
		printf("  <tag type=\"video\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\n",
		gtag_data.timestamp, gtag_data.body_length, gtag_data.tag_offset );

	printf("    <videoData codecID=\"%s\"frameType=\"%s\"/>\n", gtag_data.c_codec_ID, gtag_data.c_frame_type);
		printf("  </tag>\n");
	printf("\n");
	printf("i---->%d\n",i++);
	}
}


static int add_to_list(tag_data  *pgtag_data)
{
	tag_data *temp, *new;
	
	new = malloc(sizeof(tag_data));

	memcpy(new, pgtag_data, sizeof(tag_data));

	new->next=NULL;
	new->prev=NULL;
	
#if 0
	new->tag_offset   = gtag_data.tag_offset ;
	new->body_length  = gtag_data.body_length ;
	new->body_offset  = gtag_data.body_offset;
	new->prev_tagsize = gtag_data.prev_tagsize;
	new->type         = gtag_data.type;
	new->timestamp    = gtag_data.timestamp ; 

	strcpy(new->c_type,gtag_data.c_type);
	strcpy(new->c_timestamp,gtag_data.c_timestamp);
	
	strcpy(new->c_codec_ID,gtag_data.c_codec_ID);
	strcpy(new->c_frame_type , gtag_data.c_frame_type);
	
	strcpy(new->c_sound_type   , gtag_data.c_sound_type);
	strcpy(new->c_sound_size   , gtag_data.c_sound_size);
	strcpy(new->c_sound_rate   , gtag_data.c_sound_rate);
	strcpy(new->c_sound_format , gtag_data.c_sound_format);
#endif

	if(head==NULL)
	{	head=new;
		printf("timestamp %d\r\n",gtag_data.timestamp );
	}

	else
	{
		for(temp = head ; temp->next != NULL ; temp=temp->next);

		temp->next = new;
		new->prev = temp;
		printf("timestamp %d\r\n",gtag_data.timestamp );
	}
	return 0;
}

static int print_tag_in_text(tag_data *pgtag_data)
{
	if(pgtag_data->type==8)
	{
		printf("  <tag type=\"audio\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\n",
				gtag_data.timestamp, gtag_data.body_length,gtag_data.tag_offset );
		printf("    <audioData type=\"%s\" size=\"%s\" rate=\"%s\" format=\"%s\"/>\n", 
				gtag_data.c_sound_type , gtag_data.c_sound_size,
				gtag_data.c_sound_rate , gtag_data.c_sound_format);
		printf("  </tag>\n");
	}
	else if(pgtag_data->type==9)
	{
		printf("  <tag type=\"video\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\n",
				gtag_data.timestamp, gtag_data.body_length,gtag_data.tag_offset );

		printf("    <videoData codecID=\"%s\" frameType=\"%s\"/>\n", gtag_data.c_codec_ID,gtag_data.c_frame_type);
		printf("  </tag>\n");
	}
	return 0;
}


static int video_tag(int body_length, FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		

	bytesRead = fread(buff, sizeof(unsigned char), body_length, fp);
	gtag_data.body_offset =  ftell(fp);
	gtag_data.codec_ID = buff[0] & 0x0f;
	gtag_data.frame_type = (buff[0] >> 4)&0x0f;

	video_codec( (buff[0] & 0x0f )), video_frame_type((buff[0] >> 4)&0x0f);

#ifdef XML_PRINT
	printf("    <videoData codecID=\"%s\" frameType=\"%s\"/>\n", 
			video_codec( (buff[0] & 0x0f )),
			video_frame_type((buff[0] >> 4)&0x0f));
#endif

	//fwrite(buff, sizeof(unsigned char),body_length ,fpH264 );
	return 0;
}

static int audio_tag(int body_length, FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		

	gtag_data.body_offset =  ftell(fp);
	bytesRead = fread(buff, sizeof(unsigned char), body_length, fp);

	gtag_data.sound_type = (buff[0] & 0x01);
	gtag_data.sound_size = (buff[0] & 0x02) >> 1;
	gtag_data.sound_rate = (buff[0] & 0x0C) >> 2;
	gtag_data.sound_format = (buff[0] & 0xF0) >> 4;
	sound_type(buff[0] & 0x01);
	sound_size((buff[0] & 0x02) >> 1);
	sound_rate((buff[0] & 0x0C) >> 2);
	sound_format((buff[0] & 0xF0) >> 4);


#ifdef XML_PRINT
	printf("    <audioData type=\"%s\" size=\"%s\" rate=\"%s\" format=\"%s\"/>\n", 
			sound_type((buff[0] & 0x01) >> 0),
			sound_size((buff[0] & 0x02) >> 1 ), 
			sound_rate((buff[0] & 0x0C) >> 2), 
			sound_format((buff[0] & 0xF0) >> 4));
#endif

	//fwrite(buff, sizeof(unsigned char),body_length , fpAAC);

	return 0;
}

static int read_audio_video_tag(FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int prev_tagsize;
	unsigned char type;
	unsigned int bodylength;
	unsigned int timestamp;
	int counter = 0;
	char keyframe;
	while(1)
	{  
		int nob = 0;	
		counter++;

		/*Storing Tag offset*/
		nob = fread(buff, sizeof(unsigned char), 25, fp); 

		fwrite(buff, sizeof(unsigned char), 25, fptags);

		fseek(fp, -10, SEEK_CUR);

		if(nob < 15)
			break;

		((unsigned char *)&prev_tagsize)[0] = buff[3];
		((unsigned char *)&prev_tagsize)[1] = buff[2];
		((unsigned char *)&prev_tagsize)[2] = buff[1];
		((unsigned char *)&prev_tagsize)[3] = buff[0];
		gtag_data.prev_tagsize =  prev_tagsize;

		type = buff[4];

		((unsigned char *)&bodylength)[0] = buff[7];
		((unsigned char *)&bodylength)[1] = buff[6];
		((unsigned char *)&bodylength)[2] = buff[5];
		((unsigned char *)&bodylength)[3] = 0;
		gtag_data.body_length =  bodylength;

		((unsigned char *)&timestamp)[0] = buff[10];
		((unsigned char *)&timestamp)[1] = buff[9];
		((unsigned char *)&timestamp)[2] = buff[8];
		((unsigned char *)&timestamp)[3] = 0;
		gtag_data.timestamp =  timestamp;

		gtag_data.type = type;
		gtag_data.tag_offset = ftell(fp)-11;
		if(type==8)
		{
			strcpy (gtag_data.c_type,"audio");
#ifdef XML_PRINT
			printf("  <tag type=\"audio\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%ld\">\n",
					timestamp, bodylength, (ftell(fp)-11) );
#endif
			// fwrite(buff, sizeof(unsigned char),15, fpAAC);
			audio_tag(bodylength, fp);
#ifdef XML_PRINT
			printf("  </tag>\n");
#endif
		}
		else if(type==9)
		{
			strcpy (gtag_data.c_type,"video");
#ifdef XML_PRINT
			printf("  <tag type=\"video\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%ld\">\n",
					timestamp, bodylength, (ftell(fp)-11) );
#endif
			//fwrite(buff, sizeof(unsigned char),15 ,fpH264);
			video_tag(bodylength,fp);

#ifdef XML_PRINT
			printf("  </tag>\n");
#endif
		}		
#ifndef XML_PRINT
		//print_tag_in_text(&gtag_data);
#endif
		//print_tag_in_xml(fd, gtag_data);
		//print_tag_in_excel(fd, gtag_data);
		if(gtag_data.frame_type == 1)
		add_to_list(&gtag_data);
	}

	displaylist();
	return 0;
}

int main()
{
	FILE *fp = fopen(INPUT_FILE_PATH, "rb");
	fpH264 = fopen(OUTPUT_VIDEO_ES_PATH, "wb");
	fpAAC = fopen("audio.flv", "wb");
	fpDTS = fopen(OUTPUT_DTS_PATH, "w");
	fptags = fopen("4tags.flv", "wb");

	if(( NULL == fp )||( NULL == fpH264)||(NULL == fpAAC)||(NULL == fpDTS))
	{
		printf("Failed to open the file\n");
		exit(1);
	}

	read_flv_header(fp);
	read_tag_header(fp);
	read_audio_video_tag(fp);

	fclose(fp);
	fclose(fpH264);
	fclose(fpAAC);
	fclose(fpDTS);
	fclose(fptags);

	return 0;
}


