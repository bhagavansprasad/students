#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include"flv.h"
#include<string.h>
#include<malloc.h>

#define Audio 8
#define Video 9
#define ScriptData 18

void chk_retval(FILE *fp, char *buff, int byt_sz)
{
	int retval;
	if((retval = fread(buff, byt_sz, 1, fp)) == 0)
	{
		//perror("Can not read file");
		exit(1);
	}	
}

int byte_to_int_conversion(char *buff, int start, int how_many)
{
	int i = 0, totalbytes = start + how_many, value=0;
	for(i=start; i < totalbytes; i++)
	{
		value|= ((buff[i]) & 0xff);
		if(i == totalbytes - 1)
			break;
		value = (value << 8);
	}
	return value;
}

void read_flv_header(FILE *fp,flv_header *flvheader)
{
	char buff[10],type;
	
	chk_retval(fp, buff, 9);
	buff[10] = '\0';
	
	flvheader->signature[0] = buff[0];
	flvheader->signature[1] = buff[1];
	flvheader->signature[2] = buff[2];
	

	if((flvheader->signature[0] !='F') && (flvheader->signature[1] !='L') && (flvheader->signature[2] !='V'))
	{
		if((flvheader->signature[0] !='f') && (flvheader->signature[1] !='l') && (flvheader->signature[2] !='v'))
		{
			perror("Not FLV file");
			exit(1);
		}
	}
	

	flvheader->signature[3] ='\0';
#if 1	
	flvheader->version = byte_to_int_conversion(buff, 3, 1);
	type = byte_to_int_conversion(buff, 4, 1);
	
	flvheader->video = type & 0x01;

	flvheader->audio = type & 0x04;
	if(flvheader->audio == 0x04)
		flvheader->audio = 1;
	flvheader->dataoffset = byte_to_int_conversion(buff, 5, 4);
//	printf("\n---------------  FLV Header  ------------\n");
	printf("File type: %s\nVersion: %d\n",flvheader->signature, flvheader->version);
	printf("has audio: %s\n", flvheader->audio ? "yes" : "no");
    	printf("has video: %s\n", flvheader->video ? "yes" : "no");
    	printf("DataOffset: %d\n",flvheader->dataoffset);

#endif
	
}

void read_flv_body(FILE *fp, flv_tag *f_tags)
{
	char buff[1000];
	int prev_tag;

	chk_retval(fp, buff, 4);
	
	prev_tag = byte_to_int_conversion(buff, 0, 3);

	//printf("  </tag>\n");
	chk_retval(fp, buff, 11);
	
	buff[12]='\0';

	f_tags->filter = (byte_to_int_conversion(buff, 0, 1)&0x20) >> 5;
#if 1	
	f_tags->tagtype = byte_to_int_conversion(buff, 0, 1) &0x1f;
	f_tags->datasize = byte_to_int_conversion(buff, 1, 3) &0x00ffffff;
	f_tags->timestamp = byte_to_int_conversion(buff, 4, 3) & 0x00ffffff;
	f_tags->timestamp_extended = byte_to_int_conversion(buff, 7, 1) & 0xff;
	f_tags->streamID = byte_to_int_conversion(buff, 8, 3) & 0x00ffffff;
	if(f_tags->tagtype != Video && f_tags->tagtype != Audio && f_tags->tagtype != ScriptData)
	{
		printf(" </tag>\n</flv>");
		exit(1);
	}

	
#endif
}

void display_flvbody(flv_tag *f_tags)
{

	printf(" Filter :%2d Tag_Type: %2d  DataSize: %d TimeStamp: %2d TimeStpExtend:  %2d StreamID: %2d\n",f_tags->filter,f_tags->tagtype,f_tags->datasize,f_tags->timestamp,f_tags->timestamp_extended,f_tags->streamID);


}

void read_flv_scriptData(FILE *fp, flv_scriptData *s_data, flv_tag *f_tags)
{
	unsigned char buff[10000];
	memset(buff, 0, 10000);
	s_data->offset = (ftell(fp))-11;	
	chk_retval(fp, buff,f_tags->datasize) ;
	
	buff[844] = '\0';
	
	printf("\n  <tag type=\"scriptData\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\n\n",f_tags->timestamp,f_tags->datasize,s_data->offset);
	

}

void read_flv_videoTags(FILE *fp, flv_video_tag *video_tags,flv_tag *f_tags)
{
	unsigned char buff[10000];
	video_tags->offset = (ftell(fp))- 11;
	
	chk_retval(fp, buff,6);
	
	buff[7] = '\0';
	video_tags->frame_type = ((byte_to_int_conversion(buff, 0, 1)&0xf0)>>4);
	video_tags->codec_ID = ((byte_to_int_conversion(buff, 0, 1)&0x0f)>>0);
	if(video_tags->codec_ID == 7)
	{
		video_tags->AVCPacket_type = (byte_to_int_conversion(buff, 1, 1)&0x00ff);
		video_tags->composition_time = (byte_to_int_conversion(buff, 2, 3)&0x00ffffff);
	}
	if(video_tags->frame_type == 5)
	{
		video_tags->video_tagBody = (byte_to_int_conversion(buff, 5, 1)&0xff);
	}
	

	fseek(fp,(f_tags->datasize)-6,SEEK_CUR);
#if 0
	if((retval = fread(buff, f_tags->datasize, 1, fp)) == -1)
	{
		perror("Can not read file");
		exit(1);
	}	
#endif
}

void print_VideoTags(flv_video_tag *video_tags, flv_tag *f_tags)
{

	printf("  <tag type=\"video\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\n",f_tags->timestamp,f_tags->datasize,video_tags->offset);
	
	switch(video_tags->codec_ID)
	{
		case 2: printf("    <videoData codecID=\"Sorenson H.263\"");
			break;
		case 3: printf("    <videoData codecID=\"Screen video\"");
			break;
		case 4: printf("    <videoData codecID=\"On 2 VP6\"");
			break;
		case 5: printf("    <videoData codecID=\"On 2 VP6 with alpha channel\"");
			break;
		case 6: printf("    <videoData codecID= \"Screen video version 2\"");
			break;
		case 7: printf("    <videoData codecID=\"AVC\"");
			break;
					
	}
	
	switch(video_tags->frame_type)
	{
		case 1: printf(" frametype=\"key frame\"/>\n");
			break;
		case 2: printf(" frametype=\"inter frame\"/>\n");
			break;
		case 3: printf(" frametype=\"disposable intreframe \"/>\n");
			break;
		case 4: printf(" frametype=\"generated key frame\"/>\n");
			break;
		case 5: printf(" frametype=\"video info \"/>\n");
			break;
	}
}

void read_flv_audioTags(FILE *fp, flv_audio_tag *audio_tags, flv_tag *f_tags)
{
	unsigned char buff[1000];
	audio_tags->offset = (ftell(fp)) - 11;
		
	chk_retval(fp, buff, 2);
	
	audio_tags->soundType = ((byte_to_int_conversion(buff, 0, 1)&0x01)>>0);
	audio_tags->soundSize = ((byte_to_int_conversion(buff, 0, 1)&0x02)>>1);
	audio_tags->soundRate = ((byte_to_int_conversion(buff, 0, 1)&0x0c)>>2);		
	audio_tags->soundFormat = ((byte_to_int_conversion(buff, 0, 1)&0xf0)>>4);
	if(audio_tags->soundFormat == 10)
		audio_tags->AAC_packet_type = ((byte_to_int_conversion(buff, 1, 1)&0x00ff));
	
//	chk_retval(fp, buff, (f_tags->datasize)-2);
	fseek(fp,(f_tags->datasize)-2,SEEK_CUR);
}

void print_AudioTags(flv_audio_tag *audio_tags, flv_tag *f_tags)
{

	printf("  <tag type=\"audio\"");
	printf(" timestamp=\"%d\" dataSize=\"%d\" offset=\"%d\">\n",f_tags->timestamp,f_tags->datasize,audio_tags->offset);
	
	if(audio_tags->soundType == 1)
		printf("    <audioData type=\"stereo\"");
	else
		printf("    <audioData type=\"mono\"");
	if(audio_tags->soundSize == 0)
		printf(" size=\"8\"");
	else
		printf(" size=\"16\"");
	
	switch(audio_tags->soundRate)
	{
		case 0: printf(" rate=\"5.5\"");
			break;
		case 1: printf(" rate=\"11\"");
			break;
		case 2: printf(" rate=\"22\"");
			break;
		case 3: printf(" rate=\"44\"");
			break;
	}

switch(audio_tags->soundFormat)
	{
	case 0:
		printf(" format= \"Linear PCM,platform endian\" />\n");
		break;
	case 1:
		printf(" format=\"ADPCM\" />\n");
		break;
	case 2:
		printf(" format=\"MP3\" />\n");
		break;
	case 3:
		printf(" format=\"Linear PCM,little endian\" />\n");
		break;
	case 4:
		printf(" format=\"Nellmoser 16 kHz mono\" />\n");
		break;
	case 5:
		printf(" format=\"Nellmoser 8kHz mono\" />\n");
		break;
	case 6:
		printf(" format=\"Nellymoser\" />\n");
		break;
	case 7:
		printf(" format=\"G.711 A-law logerthmic PCM\" />\n");
		break;
	case 8:
		printf(" format=\"G.711 mu-lawlogarthmic PCM\" />\n");
		break;
	case 9:
		printf(" format=\"reserved\"/>\n");
		break;
	case 10:
		printf(" format=\"AAC\"/>\n");
		break;
	case 11:
		printf(" format=\"Speex\"/>\n");
		break;
	case 14:
		printf(" format=\"MP3 8 kHz \"/>\n");
		break;
	case 15:
		printf(" format=\"Device specific sound \"/>\n");
		break;
	}


}

main(int argc,char *argv[])
{

	flv_header flvheader;
	flv_tag f_tags;
	flv_scriptData s_data;
	flv_video_tag video_tags;
	flv_audio_tag audio_tags;
	
	FILE *fp;

	if(argc <= 1)
	{
		perror("File not specified");
		exit(1);
	}
	
	fp =fopen(argv[1],"rb");
	
	if(fp == NULL)
	{
		perror("Cannot open file");
		exit(1);
	}
	read_flv_header(fp, &flvheader);

	for(;;)
	{
		read_flv_body(fp, &f_tags);
		//display_flvbody(&f_tags);
		if(f_tags.tagtype == ScriptData)
			read_flv_scriptData(fp, &s_data, &f_tags);
		//read_flv_body(fp, &f_tags);
	
		else if(f_tags.tagtype == Video) {
			read_flv_videoTags(fp, &video_tags,&f_tags);
			print_VideoTags(&video_tags, &f_tags);
		}
		else if(f_tags.tagtype == Audio){
			read_flv_audioTags(fp, &audio_tags, &f_tags);
			print_AudioTags(&audio_tags, &f_tags);
		}
	}
	fclose(fp);
}
