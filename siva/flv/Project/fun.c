#include<stdio.h>
#include<stdlib.h>
#include "flv.h"


void dump_flv_header(flv_header *fh)
{
	printf("-->Signature :%s\n", fh->signature);

	if(fh->version == 1)
		printf("-->version :%d\n",fh->version);
	else
		printf("-->Invalid version :%d\n", fh->version);

	printf("FLAG =%d\n",fh->flag);
	if(fh->flag==5)
	{   		
		check_position(5,0,2);  //calling function for check audio are video
	}	 
	else
	{	
		printf("FLAG IS NOT 5\n",fh->flag);
	}

	int i;
	i=swap_uint32(fh->byte_off_set);  //MACRO CALL
	printf("BYTE OFFSET=%d\n",i);

}


void dump_flv_body(flv_tag  *bh, int size,unsigned int p,unsigned int time)
{
	int k=34;
	unsigned char *t;
	int j;
	static  int offset=13;
	/*t=&j;
	*(t)=bh->time_stamp[2];
	*(t+1)=bh->time_stamp[1];
	*(t+2)=bh->time_stamp[0];
	*(t+3)=0;*/
	printf(" timestamp=%c%d%c ",k,time,k);

	//printf(" Type=%d",bh->type);

	printf("dataSize=%c%d%c",k,size,k);

	//printf("TIME STAMP EXTENDED =%d\n",bh->time_stamp_extended);

	 offset = offset+p+4;
	printf(" offset=%c%d%c>\n",k,offset,k);

/*	int k;char *s;
	s=bh->stream_id;
	printf("STREAM_ID=");
	for(k=0;k<3;k++)
	{
		printf("%X",*s);
		s++;
	}
	printf("\n");*/

}

void check_position(int n,int pos1,int pos3)
{

	int mask,k,bit;
	mask=1<<(pos1);
	bit=n&mask;
	if(bit==0)
	{
		printf("---->PRESENT FILE HAVE NO VIDEO\n");
	}
	else
	{
		printf("---->VIDEO TAG IS PRESENT\n");
	}
	mask=1<<(pos3);
	k=n&mask;
	if(bit==0)
	{
		printf("---->PRESENT FILE HAVE NO AUDIO\n");
	}
	else
	{
		printf("---->AUDIO TAG IS PRESENT\n");
	}

}

int check_filter_type(int fd, unsigned char *type, int *size)
{
	char filter;
	filter=*type & 4 >> 4;
	switch(filter)
	{
		case NO_PRE_PROCESSING: 
		//	printf("No Pre Processing is Required\n");
			break;
		case PRE_PROCESSING:
		//	printf("Pre Processing of the packet is  required\
		//			beforeit can be rendered\n");
			break;
		default:printf("Invalid Filter\n");
	}
	return filter;
}
void check_tag_type(int fd,unsigned char *tagg,int *size,unsigned char filter,unsigned int p,unsigned int *time)
{
    flv_tag tag;
	flv_video video;
	flv_audio audio;
	flv_meta_data meta_data;
	int i=3,k,type,val,d=34;
	k=(*tagg)<<3;
	type=k>>3;

	switch(type)
	{

		case TAG_META_DATA:
		//	printf("<tag type=%cMETA DATA %c\n",d,d);
			//	read_meta_data(int fd,&meta_data,filter);
            //dump_flv_body(&tag,*size,p);


			lseek(fd,*size,SEEK_CUR);
			//printf("\n");
			break;

		case TAG_AUDIO_DATA:
			printf("  <tag type=%caudio%c",d,d);
            dump_flv_body(&tag,*size,p,*time);
            
			read_audio_data(fd,&audio,filter);
			lseek(fd,(*size-2),SEEK_CUR);
		//	printf("\n");
			break;
		case TAG_VIDEO_DATA:

			printf("  <tag type=%cvideo%c",d,d);
			dump_flv_body(&tag,*size,p,*time);

			read_video_data(fd,&video,filter);
			lseek(fd,(*size-5),SEEK_CUR);
			//printf("\n");
			break;
		//default:
			//printf("</flv>");

	}
}	
/*void read_meta_data(int fd, flv_meta_data *meta_data,unsigned char filter)
  {
  int val=0;

  check_meta_data_encrypt(filter);
  val=read(fd,&meta_data->script_type,1);
  check_script_type(&meta_data->script_type);
  }

  void check_script_type(unsigned char *script_type)
  {
  switch(*script_type)
  {
  case NUMBER:
  printf("Script Type is Number\n");
  break;
  case BOOLEAN:
  printf("Script Type is Boolean\n");
  break;
  case STRING:
  printf("Script Type is String\n");
  break;
  case OBJECT:
  printf("Script Type is Object\n");
  break;
  case MOVE_CLIP:
  printf("Script Type is Move Clip\n");
  break;
  case Null:
  printf("Script Type is Null\n");
  break;
  case UNDEFINED:
  printf("Script Type is Undefined\n");
  break;
  case REFERENCE:
  printf("Script Type is Reference\n");
  break;
  case ECMA_ARRAY:
  printf("Script Type is Ecma ARRAY\n");
  break;
  case OBJECT_END_MARKER:
  printf("Script Type is Object End Marker\n");
  break;
  case STRICT ARRAY:
  printf("Script Type is Strict Array\n");
  break;
  case DATE:
  printf("Script Type is Date\n");
  break;
  case LONG_STRING:
  printf("Script Type is Long String\n");
  break;
  default:
  printf("Invalid Script Data Value\n");		
  }
  }
  void check_meta_data_encrypt(filter)
  {
  if(filter == 1)
  {
  printf("Meta data body encrypted\n");
  }
  else
  {
  printf("Script TAG BODY\n");
  }
  }*/
void read_audio_data(int fd,flv_audio *audio,unsigned char filter)
{	
	int val=0;
	unsigned char format,aac_packet_type;
	val=read(fd,&audio->sound,1);
	check_sound_type(&audio->sound);
	check_sound_size(&audio->sound);
	check_sound_rate(&audio->sound);
        format=check_sound_format(&audio->sound);

	val=read(fd,&audio->aac_packet_type,1);
	aac_packet_type=check_aac_packet_type(&format,&audio->aac_packet_type);
	check_sound_data(&format,aac_packet_type);
	check_audio_encrypted(filter);

}

void check_audio_encrypted(unsigned char filter)
{
	if(filter == 1)
	{
	//	printf("audio body encrypted\n");
	}
	else
	{
	//	printf("AUDIO TAG BODY\n");
	}
}

void check_sound_data(unsigned char *sound_format,unsigned char aac_packet_type)
{
	if(*sound_format == 10)
	{
	//	printf("AAC Audio Data\n");
		check_aac_audio_packet(aac_packet_type);
	}
	else
	{
	//	printf("Varies by format\n");
	}


}

void check_aac_audio_packet(unsigned char aac_packet_type)
{
	if(aac_packet_type == 0)
	{
	//	printf("Audio Specific Config\n");
	}
	if(aac_packet_type == 1)
	{
	//	printf("Raw AAC  Frame Data \n");
	}
}


int check_sound_format(unsigned char *audio)
{
	unsigned char sound_format;
	int d1=34;
	sound_format = *audio >> 4;
	switch(sound_format)
	{
		case LINEAR_PCM_PLATFORM_ENDIAN:
			printf(" format=%cLinear PCM, platform endian%c/>\n  </tag>\n",d1,d1);
			break;
		case ADPCM: 
			printf(" format=%cADPCM%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case MP3:
			printf(" format=%cMP3%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case LINEAR_PCM_LITTLE_ENDIAN:
			printf(" format=%cLinear PCM, little endian%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case NELLYMOSER_16_KHZ_MONO:
			printf(" format=%cNellymoser 16 khz mono%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case NELLYMOSER_8_KHZ_MONO:
			printf(" format=%cNellymoser 8 khz mono%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case NELLYMOSER:
			printf(" format=%cNellymoser%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case G_711_A_LAW_LOGARITHMIC_PCM:
			printf(" format=%cG.711 A-law logarithmic PCM%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case G_711_MU_LAW_LOGARITHMIC_PCM:
			printf(" format=%cG.711 mu-law logarithmic PCM%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case RESERVED:
			printf(" format=%creserved%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case AAC:
			printf(" format=%cAAC%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case SPEEX:
			printf(" format=%cSpeex%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case MP3_8_KHZ:
			printf(" format=%cMP3 8 khz%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;

		case DEVICE_SPECIFIC_SOUND:
			printf(" format=%cDevice-Specific sound%c/>\n  </tag>\n",d1,d1);
			return sound_format;
			break;


		default:
			printf(" format=%cnot a valid sound format%c/>\n  </tag>\n",d1,d1);
			return sound_format;

	}
}


void check_sound_rate(unsigned char *sound)
{   int d1=34;
	unsigned char sound_rate;
	sound_rate = *sound & 12 >> 2;
	switch(sound_rate)
	{
		case SAMPLING_RATE_5_5_KHZ:
			printf(" rate=%c5.5%c ",d1,d1);
			break;

		case SAMPLING_RATE_11_KHZ:
			
			printf(" rate=%c11%c ",d1,d1);
			break;

		case SAMPLING_RATE_22_KHZ:
			//printf("sampling rate = 22 khz\n");
			printf(" rate=%c22 khz%c ",d1,d1);
			break;

		case SAMPLING_RATE_44_KHZ:
			//printf("sampling rate = 44 khz\n");
			printf(" rate=%c44%c",d1,d1);
			break;
		default:
			printf(" rate=%cnot valid sound_rate%c",d1,d1);

	}
}

void check_sound_size(unsigned char *sound)
{
     int d1=34;
	unsigned char sound_size;
	sound_size = *sound & 2 >> 1;
	switch(sound_size)
	{
		case BIT_8_SAMPLES:
			printf(" size=%c8%c",d1,d1);
			break;
		case BIT_16_SAMPLES:
			printf(" size=%c16%c",d1,d1);
			break;
		default:
			printf(" size=%cnot valid sound size%c");
	}
}


void check_sound_type(unsigned char *s) 
{

	unsigned char sound_type;
	sound_type = (*s & 1);
	int d1=34;
	printf("    <audioData");
	switch(sound_type)
	{
		case MONO:
			printf(" type=%cmono%c",d1,d1);
			break;

		case STEREO:		
			printf(" type=%cstereo%c",d1,d1);
			break;
		default:
			printf("   type=%cNot Valid Sound Type%c",d1,d1);

	}
}


int check_aac_packet_type(unsigned char *sound_format,unsigned char *aac) 
{

	if ( *sound_format == 10)
	{
		if ( *aac == 0)
		{
	//		printf("AAC Sequence Header\n");
	    }

		else
		{
	//		printf("AAC raw\n");
	   } 
	}
	else
	{
	//	printf("it is not a aac packet\n");
	}
	return *aac;
}



void read_video_data(int fd,flv_video *video,unsigned char filter)
{
	int val=0;
	video_body body_tag;
	unsigned char codec_id,avc_packet_type,frame_id;
	val=read(fd,&video->frame_codec,1);
	codec_id = check_codec_type(&video->frame_codec);
	frame_id = check_frame_type(&video->frame_codec);


	val=read(fd,&video->avc_packet_type,1);
	avc_packet_type=check_avc_packet_type(&video->avc_packet_type,&codec_id);

	val=read(fd,&video->composition_time,3);
	video->composition_time[3]='\0';
	//check_time(&video->composition_time,&codec_id,&avc_packet_type);


	val=read(fd,body_tag.video_tag_body,1);
	check_video_encrypted(filter);
	check_video_body(&frame_id,&codec_id);
	check_avc_video_packet(&avc_packet_type);
}

void check_video_encrypted(unsigned char filter)
{

	if(filter == 1)
	{
		//printf("video body encrypted\n");
	}
	else
	{
		//printf("Video Tag Body\n");
	}
}


void check_avc_video_packet(unsigned char *avc_packet_type)
{
	if(*avc_packet_type == 0)
	{
		//printf("AVC Decoder Configuration record\n");
	}
	if(*avc_packet_type == 1)
	{
		//printf("One or More NALU\n");
	}

}

void check_video_body(unsigned char *frame_id,unsigned char *codec_id)
{
	if(*frame_id == 5)
	{
		//printf("video frame information\n");
	}
	else
	{
		if(*codec_id == 2)
		{
			//printf("H263 Video Packet\n");
		}
		if(*codec_id == 3)
		{
			//printf("Screen Video Packet\n");
		}
		if(*codec_id == 4)
		{
			//printf("Vp6 Flv Video packet\n");
		}
		if(*codec_id == 5)
		{
			//printf("Vp6 Flv Alpha Video packet\n");
		}
		if(*codec_id == 6)
		{
			//printf("Screen V2 Video packet\n");
		}
		if(*codec_id == 7)
		{
			//printf("Avc Video packet\n");
		}

	}

}


/* void check_time(unsigned char *time,unsigned char *codec_id,unsigned char *avc_packet_type)
{
	if(*codec_id == 7)
	{
		if(*avc_packet_type == 1)
		{
			//printf("---->COMPOSTION_TIME_OFFSET=%d\n",*time);
		}
		else
		{
			//printf("---->COMPOSTION_OFFSET=0\n");
		}	
	}
}*/

int check_avc_packet_type(unsigned char *packet,unsigned char *codec_id)
{
	if(*codec_id == 7)
	{
		switch(*packet)
		{
			case AVC_SEQUENCE_HEADER:
			//	printf("---->AVC SEQUENCE HEADER\n");
				break;
			case AVC_NALU:
			//	printf("---->AVC LALU\n");
				break;
			case AVC_END_SEQUENCE:
			//	printf("---->AVC end of sequence\n");
				break;
			default: printf("---->NO AVC PACKET TYPE\n");					 
		}
		return *packet;
	}
}


int check_frame_type(unsigned char *cf)
{
	char type_frame;
	int d1=34;
	type_frame=(*cf) >> 4;
	//printf("frame type value = %d\n",type_frame);
	printf(" frameType=%c",d1);
	switch(type_frame)
	{
		case KEY_FRAME:
			printf("keyframe%c/>\n  </tag>\n",d1);

			break;
		case INTER_FRAME:
			printf("inter frame%c/>\n  </tag>\n",d1);
			break;
		case DISPOSABLE_INTER_FRAME:
			printf("DISPOSABLE_INTER_FRAME%c/>\n  </tag>\n",d1);
			break;
		case GENERATED_KEY_FRAME:
			printf("GENERATED KEY FRAME%c/>\n  </tag>\n",d1);
			break;
		case VIDEO_INFO_R_COMMAND_FRAME:
			printf("VIDEO INFO  R COMMAND FRAME%c/>\n  </tag>\n",d1);
			break;
		default:						  
			printf("NO FRAMES R PRESENT%c/>\n  </tag>\n",d1);
	}
	return type_frame;
}

int check_codec_type(unsigned char *cf)
{ 
    int d1=34;
	unsigned char j,type_codec_id;
	j = (*cf)<<4;
	type_codec_id=j>>4;
	printf("    <videoData ");
	printf("codecID=%c",d1);
	//printf("CID =  %d\n",type_codec_id);

	switch(type_codec_id)
	{
		case SORENSON_H_263:
			printf("SORENSON_H.263%c",d1);
			break;
		case SCREEN_VIDEO:
			printf("SCREEN VIDEO%c",d1);
			break;
		case ON2_VP6:
			printf("ON2 VP6%c",d1);
			break;
		case ON2_VP6_ALPHA_CHANNEL:
			printf("ON2 VP6 ALPHA CHANNEL%c",d1);
			break;

		case SCREEN_VIDEO_VERSION2:
			printf("SCREEN VIDEO VERSION2%c",d1);
			break;
		case AVC:
			printf("AVC%c",d1);
			break;
		default:						  
			printf("NO FRAMES R PRESENT%c",d1);
	}
	return type_codec_id;
}
/*void dump_vedio_tag(...)
  {
  }*/
/*void dump_script_data_tag(...)
  {
  }

  void dump_audio_tag(...)
  {
  }

 */

