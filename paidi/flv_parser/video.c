/*header files*/
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<unistd.h>
#include"flv_v.h"
#define video 9
#define metadata 18
#define audio 8
/*flv_headers*/
int read_header(int fd,header l1)
{
	if(read(fd,&l1.name,3)   !=3||
			read(fd,&l1.version,1)   !=1||
			read(fd,&l1.flag,1)      !=1||
			read(fd,&l1.dataoffset,4)!=4)
	{
		return 0;
	}
	if(l1.name[0]!='F' ||l1.name[1]!='L'||l1.name[2]!='V')
	{
		return 0;
	}
	if(l1.version!=1)
	{
		return 0;
	}
	if(audio_tag(l1.flag) && video_tag(l1.flag))
	{
		return 0;
	}
	if(swap_uint32(l1.dataoffset)!=9)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void read_tag(int fd,tag t)
{
	int p,k,val;
	short int u = 34;
	char *c = (char *)&p;
	char *r = (char *)&k;
	static int offset = 9;
	vtag vt;

	read(fd,&t.previoustagsize,4);
	read(fd,&t.tagtype,1);
	read(fd,&t.datasize,3);
	read(fd,&t.timestamp,3);
	read(fd,&t.timestampextend,1);
	read(fd,&t.streamid,3);

	val = swap_uint32(t.previoustagsize);
	*(c+3)=0;
	*(c+2)=t.timestamp[0];
	*(c+1)=t.timestamp[1];
	*(c+0)=t.timestamp[2];

	*(r+3)=0;
	*(r+2)=t.datasize[0];
	*(r+1)=t.datasize[1];
	*(r+0)=t.datasize[2];
	offset+=(sizeof(t.previoustagsize))+val;

	switch(t.tagtype)
	{
		case metadata :
			printf(" ");
			lseek(fd,k,SEEK_CUR);
			break;
		case video:
			printf("<tag type=%cvideo%c ",u,u);
			pass_info(k,p,offset);
			get_videotag(fd, vt);
			lseek(fd,(k-5),SEEK_CUR);
			break;
		case audio:
		    lseek(fd,k,SEEK_CUR);
			break;
		default :printf("no tags\n");
	}

}
void get_videotag(int fd,vtag vt)
{
	read(fd,&vt.frametype,1);
	read(fd,&vt.AVCpackettype,1);
	read(fd,&vt.compositiontime,3);
	get_codecID(vt.codecID);
	get_frametype(vt.frametype);

}

main()
{
	int fd,i;
	header l1;
    tag t;
	fd= open ("sixthsense.flv",O_RDONLY);
	if(fd==-1)
	{
		perror("File is not opened\n");
		exit(0);
	}
	read_header(fd,l1);

	for( ; ; )
	{
	read_tag(fd,t);
	}
	close(fd);
}
