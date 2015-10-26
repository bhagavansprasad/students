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
#include <stdarg.h>
#include <sys/stat.h>

FILE *fpH264   = NULL;
FILE *fpAAC    = NULL;
FILE *fpDTS    = NULL;
FILE *fptags   = NULL;
FILE *falldata = NULL;
FILE *f_srt =0;
//FILE *fon_audio =NULL;
//FILE *fon_video =NULL;

int  metadata_tag_size=0;
char time_buff[1024],time_buff1[1024];
tag_data gtag_data;

static int populate_gtag_data(tag_data *pgtag_data)
{
	switch(gtag_data.sound_format)
	{
		case 0:
			strcpy(gtag_data.c_sound_format,"Linear PCM, platform endian");
			break;
		case 1:
			strcpy(gtag_data.c_sound_format,"ADPCM");
			break;
		case 2:
			strcpy(gtag_data.c_sound_format,"MP3");
			break;
		case 3:
			strcpy(gtag_data.c_sound_format,"Linear PCM, little-endian");
			break;
		case 4:
			strcpy(gtag_data.c_sound_format,"Nellymoser 16-kHz mono");
			break;
		case 5:
			strcpy(gtag_data.c_sound_format,"Nellymoser 8-kHz mono");
			break;
		case 6:
			strcpy(gtag_data.c_sound_format,"Nellymoser");
			break;
		case 7:
			strcpy(gtag_data.c_sound_format,"G.711 A-law logarithmic PCM");
			break;
		case 8:
			strcpy(gtag_data.c_sound_format,"G.711 mu-law logarithmic PCM");
			break;
		case 9:
			strcpy(gtag_data.c_sound_format,"reserved");
			break;
		case 10:
			strcpy(gtag_data.c_sound_format,"AAC");
			break;
		case 11:
			strcpy(gtag_data.c_sound_format,"Speex");
			break;
		case 14:
			strcpy(gtag_data.c_sound_format,"MP3 8-Khz");
			break;
		case 15:
			strcpy(gtag_data.c_sound_format,"Device-specific sound");
			break;
		default:
			printf("%d\n",gtag_data.sound_format );
			break;
	}

	/* sound size*/

	switch(gtag_data.sound_size)
	{
		case 0:
			strcpy(gtag_data.c_sound_size,"8-bit samples" );	
			break;
		case 1:	
			strcpy(gtag_data.c_sound_size,"16");
			break;
	}

	/* sound rate */	
	switch(gtag_data.sound_rate )
	{
		case 0:
			strcpy(gtag_data.c_sound_rate,"55");
			break;
		case 1:
			strcpy(gtag_data.c_sound_rate,"11 KHz"); 
			break;
case2:	
			strcpy(gtag_data.c_sound_rate,"22 KHz");
			break;
case3:	
			strcpy(gtag_data.c_sound_rate,"44 KHz"); 
			break;
	}
	/* sound type */	

	switch(gtag_data.sound_type)
	{	
		case 0:	
			strcpy(gtag_data.c_sound_type,"Mono sound"); 
			break;
		case 1:	
			strcpy(gtag_data.c_sound_type,"stereo");
			break;
	}

	/* video data */ 
	/* codec ID */
	switch (gtag_data.codec_ID)
	{
		case 2:
			strcpy(gtag_data.c_codec_ID, "Sorenson H.263"); 
			break;
		case 3:
			strcpy(gtag_data.c_codec_ID, "On2 VP6"); 
			break;
		case 4:
			strcpy(gtag_data.c_codec_ID, "Sorenson H.263"); 
			break;
		case 5:
			strcpy(gtag_data.c_codec_ID, "On2 VP6 with alpha channelo"); 
			break;
		case 6:
			strcpy(gtag_data.c_codec_ID, "Screen video version 2"); 
			break;
		case 7:
			strcpy(gtag_data.c_codec_ID, "AVC"); 
			break;
	}

	/* video frame _type*/	

	switch (gtag_data.codec_ID)
	{
		case 1:
			strcpy(gtag_data.c_frame_type,"keyframe");
			break;
		case 2:
			strcpy(gtag_data.c_frame_type,"inter frame");
			break;
		case 3:
			strcpy(gtag_data.c_frame_type,"disposable inter frame");
			break;
		case 4:
			strcpy(gtag_data.c_frame_type,"generated keyframe");
			break;
		case 5:
			strcpy(gtag_data.c_frame_type,"video info/command frame");
			break;
	}
	return 0;
}

static int print_flv_file_header(flv_header *pheader)
{
/*	
	printf("signature :%c%c%c\r\n", pheader->signature[0], pheader->signature[1], pheader->signature[2]);
	printf("version   :%d\r\n", pheader->version);
	printf("flags     :%d\r\n", pheader->flags);
	printf("offset    :%x\r\n", pheader->offset);
	printf("\n\n");
	return 0;
*/

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
	fwrite(destBuf, sizeof(unsigned char), 9, fpH264);
	fwrite(destBuf, sizeof(unsigned char), 9, fpAAC);

	fwrite(destBuf, sizeof(unsigned char), 9, falldata);

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

	metadata_tag_size=ptag->body_length+11;

	return 0;

}

static int print_flv_file_tag(flv_tag *ptag)
{
/*	
	printf("-->previoustag        :%d\r\n", ptag->previous_tag_size); 
	printf("-->type               :%d\r\n", ptag->type); 
	printf("-->dataSize           :%d\r\n", ptag->body_length); 
	printf("-->offset             :%d\r\n", 0x0); 
	printf("-->time_stamp         :%d\r\n", ptag-> timestamp); 
	printf("\n\n");
*/	
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
	fwrite(buff, sizeof(unsigned char),ptag->body_length , falldata);
	//getMetadataInfo(buff, bytesRead);

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
	fwrite(destBuf, sizeof(unsigned char), 15, falldata);

	populate_flv_file_tag(&tag, destBuf);
	print_flv_file_tag(&tag);
	read_metadata(&tag, fp);

	return 0;
}

int print_tag_in_text(int n, tag_data *pgtag_data)
{

//	printf("<previoustag> =\"%d\"  <tag type=\"%s\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\n ",gtag_data.prev_tagsize , gtag_data.c_type , gtag_data.timestamp ,gtag_data.body_length, gtag_data.body_offset);

	printf("  <tag type=\"%s\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\n ",gtag_data.c_type , gtag_data.timestamp ,gtag_data.body_length, gtag_data.body_offset);
	if(n==9)
	{	
		
	//		printf(" <====videoData codecID=\"%d\" frameType=\"%d\"/>\r\n",	gtag_data.codec_ID, gtag_data.frame_type);
		printf("   <videoData codecID=\"%s\" frameType=\"%s\"/>\r\n", gtag_data.c_codec_ID, gtag_data.c_frame_type);
		printf("</tag>\n");
	}
	else if(n==8)
	{
		printf("   <audioData type=\"%s\" size=\"%s\" rate=\"%s\" format=\"%s\"/>\r\n",	gtag_data.c_sound_type, gtag_data.c_sound_size, gtag_data.c_sound_rate, gtag_data.c_sound_format );
		printf("</tag>\n");
	}

	return 0;

}


static int video_tag(int body_length, FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		
	unsigned char temp = 0;
	bytesRead = fread(buff, sizeof(unsigned char), body_length, fp);

	gtag_data.body_offset =  ftell(fp);
	gtag_data.codec_ID = buff[0] & 0x0f;
	gtag_data.frame_type = (buff[0] >> 4)&0x0f;

//		printf(" <videoData codecID=\"%s\" frameType=\"%s\"/>\r\n",	gtag_data.c_codec_ID, gtag_data.c_frame_type);
	//		printf(" <====videoData codecID=\"%d\" frameType=\"%s\"/>\r\n",	gtag_data.codec_ID, gtag_data.c_frame_type);

	/*
	//fprintf(fon_video,"\t%s \t %s \t\r\n",video_codec( (buff[0] & 0x0f )), video_frame_type((buff[0] >> 4)&0x0f));
	 */	
	fwrite(buff, sizeof(unsigned char),body_length ,fpH264 );
	fwrite(buff, sizeof(unsigned char),body_length , falldata);
	return 0;
}

static int audio_tag(int body_length, FILE *fp)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int bytesRead = 0;		

	bytesRead = fread(buff, sizeof(unsigned char), body_length, fp);

	gtag_data.sound_type = (buff[0] & 0x01);
	gtag_data.sound_size = (buff[0] & 0x02) >> 1;
	gtag_data.sound_rate = (buff[0] & 0x0C) >> 2;
	gtag_data.sound_format = (buff[0] & 0xF0) >> 4;

//		printf("    <audioData type=\"%s\" size=\"%s\" rate=\"%s\" format=\"%s\"/>\r\n",	gtag_data. c_sound_type, gtag_data. c_sound_size, gtag_data.c_sound_rate, gtag_data.c_sound_format  );


	/*
	   printf("    <audioData type=\"%s\" size=\"%s\" rate=\"%s\" format=\"%s\"/>\r\n", 
	   sound_type((buff[0] & 0x01) >> 0),sound_size((buff[0] & 0x02) >> 1 ), 
	   sound_rate((buff[0] & 0x0C) >> 2),sound_format((buff[0] & 0xF0) >> 4));

	   fprintf(fon_audio,"%s\t\t%s\t\t%s\t\t%s\t\t\r\n",
	   sound_type((buff[0] & 0x01) >> 0), sound_size((buff[0] & 0x02) >> 1 ), 
	   sound_rate((buff[0] & 0x0C) >> 2),sound_format((buff[0] & 0xF0) >> 4));

	 */
	fwrite(buff, sizeof(unsigned char),body_length , fpAAC);
	fwrite(buff, sizeof(unsigned char),body_length , falldata);
	return 0;
}


static calculate(int someNumber,int n)
{
	int rem,hh,mm,ss,ml;
	static int hh1=0,mm1=0,ss1=0,ml1=0;
	static int i=1;
	char buffer[1024];
	int count=0;	

	ml  = someNumber%1000;
	rem = someNumber/1000;	

	ss  = rem%60;
	rem = rem/60;	

	mm=rem %60;
	hh = rem/60;	

	count = sprintf(time_buff, "%d\n%02d:%02d:%02d,%02d -->"
			"%02d:%02d:%02d,%02d\n%d\n\n", i, hh1,mm1,ss1,ml1, hh,mm,ss,ml, i);

	/*	
		if(n==8)
		fprintf(fon_audio," %02d:%02d:%02d,%02d\t",hh,mm,ss,ml);
		else
		fprintf(fon_video," %02d:%02d:%02d,%02d\t",hh,mm,ss,ml);
	 */	
	fputs(time_buff, f_srt);
	hh1=hh;mm1=mm;ss1=ss;ml1=ml;
	//	printf("count -->%d",count);
	//	printf("buffer-->%s\n",time_buff);

	i++;
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
	char buffer[1050];
	while(1)
	{  
		int nob = 0;	
		gtag_data.tag_offset = ftell(fp);;
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

				gtag_data.type = type;
				strcpy (gtag_data.c_type,"audio");
				((unsigned char *)&prev_tagsize)[0] = buff[3];
				((unsigned char *)&prev_tagsize)[1] = buff[2];
				((unsigned char *)&prev_tagsize)[2] = buff[1];
				((unsigned char *)&prev_tagsize)[3] = buff[0];
				gtag_data.prev_tagsize =  prev_tagsize;

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

				buff[3]=    ((unsigned char *)&metadata_tag_size)[0];
				buff[2]=	((unsigned char *)&metadata_tag_size)[1];
				buff[1]=	((unsigned char *)&metadata_tag_size)[2];
				buff[0]=	((unsigned char *)&metadata_tag_size)[3];

		//	printf("<tagprev_tagsize \"%d\" type=\"%s\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\r\n", 	gtag_data.prev_tagsize,	gtag_data.c_type ,gtag_data.timestamp,gtag_data.body_length, gtag_data.tag_offset=(ftell(fp)-11));

//			printf("tag type=\"%s\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\r\n", 	gtag_data.c_type ,gtag_data.timestamp,gtag_data.body_length, gtag_data.tag_offset=(ftell(fp)-11));

				// metadata_tag_size,timestamp, bodylength,(ftell(fp)-11) );

				//gtag_data.timestamp = (ftell(fp)-11);
				calculate(timestamp,type);
		
		//	fprintf(fon_audio," %d \t\taudio \t %d\t %d\t%ld \t",prev_tagsize,timestamp, bodylength,(ftell(fp)-11) );
				
				fwrite(buff, sizeof(unsigned char), 15, fpAAC);
				fwrite(buff, sizeof(unsigned char), 15, falldata);
				memcpy(audio_buff, buff, 25);
				audio_tag(bodylength,fp);
				//printf("  </tag>\r\n");
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
				
				gtag_data.type = type;

				strcpy (gtag_data.c_type,"audio");
				((unsigned char *)&prev_tagsize)[0] = buff[3];
				((unsigned char *)&prev_tagsize)[1] = buff[2];
				((unsigned char *)&prev_tagsize)[2] = buff[1];
				((unsigned char *)&prev_tagsize)[3] = buff[0];
			
				gtag_data.prev_tagsize =  prev_tagsize;

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
				
				if(i==1)
					i++;
				else
					prev_tagsize=prev_tagsize+11;

				buff[3]= ((unsigned char *)&prev_tagsize)[0];
				buff[2]= ((unsigned char *)&prev_tagsize)[1];
				buff[1]= ((unsigned char *)&prev_tagsize)[2];
				buff[0]= ((unsigned char *)&prev_tagsize)[3];

	
//		printf("<tagprev_tagsize \"%d\" type=\"%s\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%ld\">\r\n",gtag_data.prev_tagsize,	gtag_data.c_type ,gtag_data.timestamp,gtag_data.body_length, gtag_data.tag_offset=(ftell(fp)-11));
				 
//			printf("tag type=\"%s\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\r\n", 	gtag_data.c_type ,gtag_data.timestamp,gtag_data.body_length, gtag_data.tag_offset=(ftell(fp)-11));
				
				//gtag_data.timestamp = (ftell(fp)-11);
				calculate(timestamp,type);

			//fprintf(fon_audio," %d \t\taudio \t%d\t%d\t%ld \t",prev_tagsize,timestamp, bodylength,(ftell(fp)-11) );
				
				fwrite(buff, sizeof(unsigned char), 15, fpAAC);
				fwrite(buff, sizeof(unsigned char), 15, falldata);
				memcpy(audio_buff, buff, 25);
				audio_tag(bodylength,fp);
				//printf("  </tag>\r\n");
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
			gtag_data.type = type;
			strcpy (gtag_data.c_type,"video");
			((unsigned char *)&prev_tagsize)[0] = buff[3];
			((unsigned char *)&prev_tagsize)[1] = buff[2];
			((unsigned char *)&prev_tagsize)[2] = buff[1];
			((unsigned char *)&prev_tagsize)[3] = buff[0];
			
			gtag_data.prev_tagsize =  prev_tagsize;
			
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
			if(i==1)
				i++;
			else
				prev_tagsize=prev_tagsize+11;

			//	prev_tagsize=prev_tagsize+11;
			buff[3]=  ((unsigned char *)&prev_tagsize)[0];
			buff[2]=	((unsigned char *)&prev_tagsize)[1];
			buff[1]=	((unsigned char *)&prev_tagsize)[2];
			buff[0]=	((unsigned char *)&prev_tagsize)[3];


//			printf("tag type=\"%s\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\r\n", 	gtag_data.c_type ,gtag_data.timestamp,gtag_data.body_length, gtag_data.tag_offset=(ftell(fp)-11));

//		printf("<tagprev_tagsize \"%d\" type=\"%s\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%ld\">\r\n",	gtag_data.prev_tagsize,	gtag_data.c_type,gtag_data.timestamp,gtag_data.body_length, gtag_data.tag_offset=(ftell(fp)-11));
		
			calculate(timestamp,type);
	//		gtag_data.timestamp = (ftell(fp)-11);

		//	fprintf(fon_video," %d\t\t  video    %d   %d%ld  ",prev_tagsize,timestamp, bodylength,(ftell(fp)-11) );

			
			fwrite(buff,sizeof(unsigned char),15,fpH264);
			fwrite(buff, sizeof(unsigned char), 15, falldata);
			memcpy(video_buff, buff, 25);
			video_tag(bodylength,fp);
			//	printf("  </tag>\r\n");
		}		
		if(nob < 15)
		{
			printf("\t\t\t------------file ended----------\r\n");
			break;
		}
		populate_gtag_data(&gtag_data);
		print_tag_in_text(type, &gtag_data);
		
		}

			while(count< 15)
			break;
	return 0;
}

int main()
{

	int fd;
	FILE *fp = fopen(INPUT_FILE_PATH, "rb");
	fpH264   = fopen(OUTPUT_VIDEO_ES_PATH, "wb");
	fpDTS    = fopen(OUTPUT_DTS_PATH , "w");

	fpAAC    = fopen("audio.mp3", "wb");
	fptags   = fopen("4tags.flv", "wb");
	falldata = fopen("mohansai.flv", "wb");
	f_srt    = fopen("stress.srt", "wb");
//	fon_audio = fopen("onlyaudio","wb");
//	fon_video = fopen("onlyvideo","wb");

//	fprintf(fon_video,"rawtimestamp\t prev_tagsize\t type\t timestamp\tbodylength\toffset\tcodecID\tframeType\t \r\n" );
//	fprintf(fon_audio,"rawtimestamp\t prev_tagsize\t type\t timestamp\tbodylength\toffset\t type\tsize\trate\t     format\t \r\n" );
				
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
	fclose(fptags);

	return 0;
}
