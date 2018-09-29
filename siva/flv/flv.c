#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include "flv.h"


int open_file(char *filename)
{
	int fd;

	fd=open(filename, O_RDONLY);

	if(fd==-1)
	{
		perror("error: File open failed\n");
		exit(0);
	}

	return fd;
}

void read_header(int fd, flv_header *phead)
{
      	int val=0;

	val = read(fd, phead->signature, 3);
	phead->signature[4]='\0';

	if((strncmp(phead->signature, "FLV", 3) != 0))
	{	
		printf("Invalid Signature :%s\n", phead->signature);
		exit(1);
	}

	val=read(fd,&phead->version,1);
	val=read(fd,&phead->flag,1);
	val=read(fd,&phead->byte_off_set,4);

   
}

/*int read_previous_tag(int fd,flv_previous_tag *tag)
{
	int val=0,i; 
	val=read(fd,&tag->previous_tag,4);
	printf("value of reading bytes==%d",val);
	i=swap_uint32(tag->previous_tag);
	return i;
}*/

void read_tag(int fd,flv_tag *th)
{
	unsigned int i;
	int val=0;
	unsigned char filter;
		
		val=read(fd,&th->previous_tag,4);
		i=swap_uint32(th->previous_tag);

		// dump_flv_previous_tag(&i);

    
	
	val=read(fd,&(th->type),1);

	val=read(fd,&th->data_size,3);
	th->data_size[4]='\0';
	char *c;
	int data_size;
	c=&data_size;
	*c=th->data_size[2];
	*(c+1)=th->data_size[1];
	*(c+2)=th->data_size[0];
	*(c+3)=0;
    //printf("*****************************************%d\n",data_size);
	val=read(fd,&th->time_stamp,3);
	th->time_stamp[4]='\0';
    
	val=read(fd,&th->time_stamp_extended,1);

	val=read(fd,&th->stream_id,3);
	th->stream_id[4]='\0';
    
	filter=check_filter_type(fd,&th->type,&data_size);
	check_tag_type(fd,&th->type,&data_size,filter); 
	
}

 
main()
{
	int fd,i;
	flv_header header;
	flv_tag tag;
	flv_video video;

	fd = open_file("sixth.flv");
	read_header(fd, &header);
	//dump_flv_header(&header);

	
	for(i=0;i<=2;i++)
	{

		read_tag(fd,&tag);
		//dump_flv_body(&tag);

	//	dump_flv_previous_tag(&p_tag);

	}



}


