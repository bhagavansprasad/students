#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include "audio_video.h"

int file_open(char *filename)
{
	int fd;

	fd=open(filename, O_RDONLY);
	if(fd == -1)
	{
		perror("ERROR :File open failed\n");
	}

	return fd;
}

int create_audio_file(char *filename)
{
	int fd;
	fd=open(filename,O_CREAT|O_RDWR,0644);
	if(fd == -1)
	{
		perror("ERROR : File Creation Failed\n");
	}

	return fd;
}

int create_video_file(char *filename)
{
	int fd;
	fd=open(filename,O_CREAT|O_RDWR,0644);
	if(fd == -1)
	{
		perror("ERROR : File Creation Failed\n");
	}

	return fd;
}

int write_audio_header(int fd,int audio_fd)
{
	int val;
	flv_header hd={"FLV",1,1,0x09000000};
	val = write(audio_fd,&hd.signature,3);
	val = write(audio_fd,&hd.version,1);
	val = write(audio_fd,&hd.flag,1);
	val = write(audio_fd,&hd.byte_off_set,4);
	return 0;
}


int write_video_header(int fd,int audio_fd)
{
	int val;
	flv_header hd={"FLV",1,4,0x09000000};

	val = write(audio_fd,&hd.signature,3);
	val = write(audio_fd,&hd.version,1);
	val = write(audio_fd,&hd.flag,1);
	val = write(audio_fd,&hd.byte_off_set,4);
	return 0;
}

int  read_tag(int fd,flv_tag th,int audio_fd,int video_fd)
{
	int val=0,val_p=0;
	unsigned char filter;
	val_p=read(fd,&th.previous_tag,4);	
	val=read(fd,&th.type,1);
	check_tag_type(fd,th.type,th.previous_tag,audio_fd,video_fd);
	return val_p;

}


void check_tag_type(int fd,unsigned char tagg,unsigned int previous_tag,int audio_fd,int video_fd)
{
	flv_tag th;
	flv_audio au;
	flv_video vd;
	unsigned int data_size;
	unsigned char buff[600000];
	unsigned char *c;
	int i=3,k,type,val,d=34;
	k=(tagg)<<3;
	type=k>>3;

	if(type == 18)
	{
		printf("script data\n");
		val = write(audio_fd,&previous_tag,4);
		val = write(audio_fd,&tagg,1);
		val = write(video_fd,&previous_tag,4);
		val = write(video_fd,&tagg,1);	

		val = read(fd,&th.data_size,3);
		val = write(video_fd,&th.data_size,val);
		val = write(audio_fd,&th.data_size,3);	
		c=&data_size;
		*c=th.data_size[2];
		*(c+1)=th.data_size[1];
		*(c+2)=th.data_size[0];
		*(c+3)=0;

		val = read(fd,&th.time_stamp,3);
		val = write(video_fd,&th.time_stamp,val);
		val = write(audio_fd,&th.time_stamp,3);	

		val = read(fd,&th.time_stamp_extended,1);
		val = write(video_fd,&th.time_stamp_extended,val);
		val = write(audio_fd,&th.time_stamp_extended,1);	

		val = read(fd,&th.stream_id,3);
		val = write(video_fd,&th.stream_id,val);
		val = write(audio_fd,&th.stream_id,3);	
		printf("---->DATA SIZE = =%d\n",data_size);

		val=read(fd,buff,data_size);
		val=write(video_fd,buff,val);
		val=write(audio_fd,buff,data_size);

		//lseek(fd,data_size,SEEK_CUR);
	}

	if(type == 8)
	{
		printf("AUDIO_DATA\n");

		val = write(audio_fd,&previous_tag,4);

		val = write(audio_fd,&tagg,1);

		val = read(fd,&th.data_size,3);
		val = write(audio_fd,&th.data_size,val);
		c = &data_size;
		*c = th.data_size[2];
		*(c+1) = th.data_size[1];
		*(c+2) = th.data_size[0];
		*(c+3) = 0;
		val = read(fd,&th.time_stamp,3);
		val = write(audio_fd,&th.time_stamp,val);

		val = read(fd,&th.time_stamp_extended,1);
		val = write(audio_fd,&th.time_stamp_extended,val);

		val = read(fd,&th.stream_id,3);
		val = write(audio_fd,&th.stream_id,val);

		printf("---->DATA SIZE = =%d\n",data_size);

		/*	val = read(fd,&au.sound,1);
			val = write(audio_fd,&au.sound,val);

			val = read(fd,&au.aac_packet_type,1);
			val = write(audio_fd,&au.aac_packet_type,1);*/

		val = read(fd,buff,data_size);
		if(val>=600000)
		{
			printf("Buffer size is less\n");
		}
		val = write(audio_fd,buff,val);
	}

	if(type == 9)
	{
		printf("VIDEO_DATA\n");

		val = write(video_fd,&previous_tag,4);

		val = write(video_fd,&tagg,1);

		val = read(fd,&th.data_size,3);
		val = write(video_fd,&th.data_size,val);
		c = &data_size;
		*c = th.data_size[2];
		*(c+1) = th.data_size[1];
		*(c+2) = th.data_size[0];
		*(c+3) = 0;
		val = read(fd,&th.time_stamp,3);
		val = write(video_fd,&th.time_stamp,val);

		val = read(fd,&th.time_stamp_extended,1);
		val = write(video_fd,&th.time_stamp_extended,val);

		val = read(fd,&th.stream_id,3);
		val = write(video_fd,&th.stream_id,val);

		printf("---->DATA SIZE = =%d\n",data_size);
		val = read(fd,buff,data_size);
		if(val>=600000)
		{
			printf("Buffer size is less\n");
		}
		val = write(video_fd,buff,val);
	}
}	


