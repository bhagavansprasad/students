#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INPUT_FILE_PATH    "t.flv"
#define MAX_STACK_BUFF 30*1024


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


/*	while(1)
	{
	read_bytes_from_file(25, to_buffer);

	copy_buffer_to(tempbuff)
	check_type if it is 8 i.e. Audio
	if so 
	{
	if (the packet is is second)
	{
	copy body_length of first tag to previous_tag_size of second tag
	b[0] = pvebuff[6]
	b[1] = pvebuff[7]
	b[2] = pvebuff[8]
	b[4] =  0
	}
	write_buffer_to(new_audio_file, to_buffer)
	}
	else if not
	{
	if (the packet is is second)
	{
//copy body_length of first tag to previous_tag_size of second tag
printf("%x", b[0]);
printf("%x", b[1]);
printf("%x", b[2]);
printf("%x", b[4]);
printf("%x", tb[0]);
printf("%x", tb[1]);
printf("%x", tb[2]);
printf("%x", tb[4]);

b[0] = pvebuff[6]
b[1] = pvebuff[7]
b[2] = pvebuff[8]
b[4] =  0
}	
write_buffer_to(new_audio_file, to_buffer)
}		
}
}
 */

// --
int i=0;
unsigned int prev_tagsize;
unsigned char type;
unsigned int bodylength;
unsigned int timestamp;




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


void video_data_display(char *buff)
{
	printf("\n--> video_data_tag <-- \n");
	//	for(i=0;i<26;i++)
	//	printf("--> %x \t ",buff[i]);

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

	printf("-->previoustag        :%d\r\n", prev_tagsize); 
	printf("-->type               :%d\r\n", type); 
	printf("-->dataSize           :%d\r\n", bodylength); 
	printf("-->time_stamp         :%d\r\n", timestamp); 


	printf("  \r\n\n  <videoData codecID=\"%s\" frameType=\"%s\"/>\r\n\n", 
			video_codec( (buff[15] & 0x0f )),
			video_frame_type((buff[15] >> 4)&0x0f));


}

void audio_data_display(char *buff)
{
	printf("\n--> audio_data_tag <-- \n");
	//	for(i=0;i<26;i++)
	//	printf("--> %x \t ",buff[i]);


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
	printf("-->previoustag        :%d\r\n", prev_tagsize); 
	printf("-->type               :%d\r\n", type); 
	printf("-->dataSize           :%d\r\n", bodylength); 
	printf("-->time_stamp         :%d\r\n", timestamp); 




	printf("    \r\n\n <audioData type=\"%s\" size=\"%s\" rate=\"%s\"format=\"%s\"/>\r\n\n", 
			sound_type((buff[11] & 0x01) >> 0),
			sound_size((buff[11] & 0x02) >> 1 ), 
			sound_rate((buff[11] & 0x0C) >> 2), 
			sound_format((buff[11] & 0xF0) >> 4));


}
static int read_audio_video_tag(FILE *fp,FILE *fa,FILE *fv)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned char audio_temp_buff[MAX_STACK_BUFF] = "\0";
	unsigned char video_temp_buff[MAX_STACK_BUFF] = "\0";
	unsigned int prev_tagsize;
	unsigned char type;
	unsigned int bodylength;
	unsigned int timestamp;
	int count=0,temp_pre_tag_size=0;

	while(1)
	{
		count=fread(buff,sizeof(unsigned char),25,fp);
		if(count != 25)   exit(0);

		type=buff[4];
//		strcpy(temp_buff,buff);

		if(type==8)
		{
		
	  		strcpy(audio_temp_buff,buff);
			buff[0] = audio_temp_buff[6];
			buff[1] = audio_temp_buff[7];
			buff[2] = audio_temp_buff[8];
			buff[4] = 0;

			fwrite(buff,sizeof(unsigned char),25,fv);
			audio_data_display(buff);
		}	

		if(type==9)
		{

		    strcpy(video_temp_buff,buff);
			buff[0] = video_temp_buff[6];
			buff[1] = video_temp_buff[7];
			buff[2] = video_temp_buff[8];
			buff[4] = 0;
			fwrite(buff,sizeof(unsigned char),25,fa);
		//	video_data_display(buff);
		}
		//		printf("%x\r\n", buff[4]);

	}


}
main()
{
	FILE *fp;
	FILE *fv;
	FILE *fa;
	fp = fopen("samp.flv","rb");
	fv = fopen("samp_video.flv","wb");
	fa = fopen("samp_audio.flv","wb");
	if(fp==NULL)
	{
		perror("error in open a file");
		exit(1);
	}
	read_audio_video_tag(fp,fa,fv);
}

