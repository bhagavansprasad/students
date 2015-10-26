#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"flv_header.h"
#define AUDIO 8
#define VIDEO 9
#define SCRIPTDATA 18

int chk_retval(FILE *fp, char *buff, int byt_sz)
{
	int retval;

	if((retval = fread(buff,byt_sz,1,fp))==0)
	{
		//		perror("Can not open file");
		printf("  </tag>\n</flv>\n");
		exit(1);
	}

	return retval;
}

int bytes_to_int(char *buff,int from,int to)
{
	int i,no_of_bytes=from+to;
	unsigned int value = 0;

	for(i =from; i<no_of_bytes; i++)
	{
		value |=((buff[i]) & 0xFF);
		if(i == no_of_bytes-1)
			break;
		value =(value<<8);
	}

	return value;
}

void read_flv_header(FILE *fp,flv_header flv_h, FILE *vfp, FILE *afp)
{
	unsigned char buff[1000];

	chk_retval(fp,buff,9);

	flv_h.signature[0] = buff[0];
	flv_h.signature[1] = buff[1];
	flv_h.signature[2] = buff[2];
	flv_h.signature[3] = '\0';

	//	buff[10]='\0';
	//	printf("buffer value :%s\n",buffer);
	//	printf("%s\n",flv_h.signature);
	fwrite(buff,9,1,vfp);
	fwrite(buff,9,1,afp);

	if(flv_h.signature[0] != 'F' && flv_h.signature[1]!='L' && flv_h.signature[2]!='V')
	{
		if(flv_h.signature[0] != 'f' && flv_h.signature[1] !='l' && flv_h.signature[2] != 'v')
		{
			printf("The File is not flv \n");
			exit(1);
		}
	}

	flv_h.version = bytes_to_int(buff,3,1);
	flv_h.audio = ((bytes_to_int(buff,4,1)) & 4 >>2);
	flv_h.video = ((bytes_to_int(buff,4,1)) & 1);
	flv_h.offset = bytes_to_int(buff,5,4);
#if 0
	printf(" File type= %s\n version= %d\n",flv_h.signature,flv_h.version);
	printf("hasVideo= %s\n",flv_h.video? "yes":"no");
	printf("hasAudio= %s\n",flv_h.audio? "yes":"no");
	printf("offset=\"%d\n",flv_h.offset);
#endif

}


void read_flv_body(FILE *fp, flv_tags *f_tag)
{
	unsigned char buff[10000];
	memset(buff,0,10000);
	unsigned int prevtag_sz = 0;

	chk_retval(fp, buff, 15);

	prevtag_sz = bytes_to_int(buff, 0, 3);

	//	chk_retval(fp,buff,11);	

	//	buff[12]='\0';	

	f_tag->Filter = ((bytes_to_int(buff, 4, 1) & 0x20) >> 5);
	f_tag->TagType = (bytes_to_int(buff,4,1)&0x1F);
	f_tag->DataSize = (bytes_to_int(buff, 5, 3) & 0x00FFFFFF);
	f_tag->Timestamp = (bytes_to_int(buff,8,3)&0x00FFFFFF);
	f_tag->TimestampExtended = (bytes_to_int(buff,11,1)&0x00FF);
	f_tag->StreamID = (bytes_to_int(buff,12,3)&0x00FFFFFF);

	printf("-->f_tag->DataSize :%d\n", f_tag->DataSize);

	if(f_tag->TagType != VIDEO && f_tag->TagType != AUDIO && f_tag->TagType != SCRIPTDATA)
	{
		//		printf("</tag>\n</flv>");
		exit(1);
	}
}

void display_flv_body(flv_tags *f_tag)
{
	printf("Filter :%d  TagType: %d  DataSize: %d  Timestamp: %d  TimestamExtended: %d  StreamID:%d\n",f_tag->Filter,f_tag->TagType,f_tag->DataSize,f_tag->Timestamp,f_tag->TimestampExtended,f_tag->StreamID);
}

void read_flv_scriptdata(FILE *fp, flv_scriptdata *f_sdata, flv_tags *f_tag, FILE *vfp, FILE *afp)
{
	unsigned char buff[10000];

	f_sdata->Offset = (ftell(fp))-11;
	//	chk_retval(fp,buff,f_tag->DataSize);

	//	fseek(fp,-((f_tag->DataSize)+15),SEEK_CUR);	
	fseek(fp, -15, SEEK_CUR);
	memset(buff, 0, 10000);	

	chk_retval(fp, buff, f_tag->DataSize);

	fwrite(buff, f_tag->DataSize, 1, afp);
	fwrite(buff, f_tag->DataSize, 1, vfp);
	/*
	   printf("  <tag type=\"scriptdata\" timestamp=\"%d\" datasize=\"%d\"offset=\"%d\">\n",f_tag->Timestamp,f_tag->DataSize,f_sdata->Offset);
	 */	
}

void read_flv_videotag(FILE *fp, flv_videotag *v_tag, flv_tags *f_tag, FILE *vfp)
{
	unsigned char buff[10000] = {0};
	v_tag->Offset = ftell(fp)-11;
#if 0
	//	chk_retval(fp,buff,6);
	//	buff[7]='\0';
	v_tag->FrameType = ((bytes_to_int(buff,0,1) & 0xF0)>>4);
	v_tag->CodecID = ((bytes_to_int(buff,0,1) & 0x0F)>>0);

	if(v_tag->CodecID == 7)
	{
		v_tag->AVCPacketType = (bytes_to_int(buff,1,1)& 0xFF);
		v_tag->CompositionTime = (bytes_to_int(buff,2,3) & 0x00FFFFFF);
	}
	if(v_tag->FrameType == 5)
		v_tag->VideoTagBody = (bytes_to_int(buff,5,1) & 0xFF);

#endif
	fseek(fp, -15, SEEK_CUR);
	chk_retval(fp, buff, f_tag->DataSize);
	fwrite(buff, f_tag->DataSize, 1, vfp);
}


void print_video_tags(flv_videotag *v_tag, flv_tags *f_tag)
{
	printf("  </tag>\n");
	printf("  <tag type=\"video\" timestamp=\"%d\"datasize=\"%d\"offset=\"%d\">\n",f_tag->Timestamp,f_tag->DataSize,v_tag->Offset);

	switch(v_tag->CodecID)
	{
		case 2:printf("    <videoData codecID=\"Sorenson H.263\"");
			   break;
		case 3:printf("    <videoData codecID=\"Screen video\"");
			   break;
		case 4:printf("    <videoData codecID=\"On2 VP6\"");
			   break;
		case 5:printf("    <videoData codecID=\"On2 VP6 with alph channel\"");
			   break;
		case 6:printf("    <videoData codecID=\"Screen video version 2\"");
			   break;
		case 7:printf("    <videoData codecID=\"AVC\"");
			   break;
	}

	switch(v_tag->FrameType)
	{
		case 1:printf(" frameType=\"key frame\"/>\n");
			   break;
		case 2:printf(" frameType=\"inter frame\"/>\n");
			   break;
		case 3:printf(" frameType=\"disposable inter frame\"/>\n");
			   break;
		case 4:printf(" frameType=\"generated key frame\"/>\n");
			   break;
		case 5:printf(" frameType=\"video info/command frame\"/>\n");
			   break;
	}		
}

void read_flv_audiotag(FILE *fp, flv_audiotag *a_tag, flv_tags *f_tag, FILE *afp)
{
	unsigned char buff[10000] = {0};
	a_tag->Offset = ftell(fp)-11;
	#if 0
	//	chk_retval(fp,buff,2);
	//	buff[3]='\0';

	a_tag->SoundFormat = ((bytes_to_int(buff,0,1)&0xF0)>>4);
	a_tag->SoundRate = ((bytes_to_int(buff,0,1)&0x0C)>>2);
	a_tag->SoundSize = ((bytes_to_int(buff,0,1)&0x02)>>1);
	a_tag->SoundType = ((bytes_to_int(buff,0,1)&0x01)>>0);

	if(a_tag->SoundFormat==10)
		a_tag->AACPacketType = (bytes_to_int(buff,1,1)&0xFF);
	#endif

	fseek(fp,-((f_tag->DataSize)+15),SEEK_CUR);
	
	chk_retval(fp, buff, f_tag->DataSize);

	fwrite(buff, f_tag->DataSize ,1 , afp);

}

void print_flv_audiotag(flv_audiotag *a_tag, flv_tags *f_tag)
{
	printf("  </tag>\n");
	printf("  <tag type=\"audio\" timestamp=\"%d\" datasize=\"%d\" offset=\"%d\">\n",f_tag->Timestamp,f_tag->DataSize,a_tag->Offset);

	if(a_tag->SoundType == 0)
		printf("    <audioData type=\"mono\"");
	else
		printf("    <audioData type=\"stereo\"");
	if(a_tag->SoundSize == 0)
		printf(" size=\"8\"");
	else
		printf(" size=\"16\"");

	switch(a_tag->SoundRate)
	{
		case 0:printf(" rate=\"5.5\"");
			   break;
		case 1:printf(" rate=\"11\"");
			   break;
		case 2:printf(" rate=\"22\"");
			   break;
		case 3:printf(" rate=\"44\"");
			   break;
	}

	switch(a_tag->SoundFormat)
	{
		case 0:printf(" format=\"Linear PCM,platform endian\"/>\n");
			   break;
		case 1:printf(" format=\"ADPCM\"/>\n");
			   break;
		case 2:printf(" format=\"Mp3\"/>\n");
			   break;
		case 3:printf(" format=\"Linear PCM, little endian\"/>\n");
			   break;
		case 4:printf(" format=\"Nellmoser 16 Khz mono\"/>\n");
			   break;
		case 5:printf(" format=\"Nellymoser 8 Khz mono\"/>\n");
			   break;
		case 6:printf(" format=\"Nellymoser\"/>\n");
			   break;
		case 7:printf(" format=\"G.711 A-law logarithmic PCM\"/>\n");
			   break;
		case 8:printf(" format=\"G.711 mu-law logarithmic PCM\"/>\n");
			   break;
		case 9:printf(" format=\"reserved\"/>\n");
			   break;
		case 10:printf(" format=\"AAC\"/>\n");
				break;
		case 11:printf(" format=\"Speex\"/>\n");
				break;
		case 14:printf(" format=\"Mp3 8khz\"/>\n");
				break;
		case 15:printf(" format=\"Device specific sound\"/>\n");
				break;
	}	
}

main(int argc, char *argv[])
{
	FILE *fp, *vfp, *afp;
	flv_header flv_h;
	flv_tags f_tag;
	flv_scriptdata f_sdata;
	flv_videotag v_tag;
	flv_audiotag a_tag;

#if 0
	if(argc <= 1)
	{
		perror("File not mentioned");
		exit(1);
	}
#endif
	fp = fopen("/home/bhagavan/students/prasanna/sixth.flv", "rb");
	if(fp==0)
	{
		perror("File is not open");
		exit(1);
	}

	vfp = fopen("video.flv","w+");
	afp = fopen("audio.flv", "w+");

	read_flv_header(fp, flv_h, vfp, afp);

	for(;;)
	{
		read_flv_body(fp, &f_tag);
		display_flv_body(&f_tag);

		if(f_tag.TagType == SCRIPTDATA)
			read_flv_scriptdata(fp, &f_sdata, &f_tag, vfp, afp);
		else if(f_tag.TagType == VIDEO)
			read_flv_videotag(fp, &v_tag, &f_tag, vfp);
		//			print_video_tags(&v_tag, &f_tag);
		else if(f_tag.TagType == AUDIO)
			read_flv_audiotag(fp, &a_tag, &f_tag, afp);
		//			print_flv_audiotag(&a_tag, &f_tag);
	}

	fclose(afp);
	fclose(vfp);
	fclose(fp);
}
