#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "flv1.h"
#include <fcntl.h>

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

int create_file(char *filename)
{
	int fd;
	fd=open(filename,O_CREAT|O_RDWR,0644);
	if(fd == -1)
	{
		perror("ERROR : File Creation Failed\n");
	}

	return fd;
}



void write_header(int fd, int fd1, flv_header hd)
{
	int val=0,i;

	val=read(fd,hd.signature,3);

	val=write(fd1,&hd.signature,val);

	val=read(fd,&hd.version,1);
	val=write(fd1,&hd.version,val);

	val=read(fd,&hd.flag,1);
	val=write(fd1,&hd.flag,val);

	val=read(fd,&hd.byte_off_set,4);
	val=write(fd1,&hd.byte_off_set,val);

		i= swap_uint32(hd.byte_off_set);
	// printf("value%d\n",i);

}

int write_tag(int fd, int fd1, flv_tag tag)
{
	unsigned int val=0, i, data_size;
	unsigned int time;
	int val1=0,val2=0,val3=0,val4=0,val5=0,val6=0,val7=0;
	unsigned char  *t,*c;
	static unsigned int t2=0;
	unsigned char buff[400000];
	static int total1=0,total2=0;

	val = read(fd,&tag.previous_tag,4);
	val = read(fd,&tag.type,1);

	val = read(fd,&tag.data_size,3);
	
	c = (char *)&data_size;
	*c = tag.data_size[2];
	*(c+1) = tag.data_size[1];
	*(c+2) = tag.data_size[0];
	*(c+3) = 0;

	val = read(fd,&tag.time_stamp,3);

	t = (unsigned char *)&time;
	*t = tag.time_stamp[2];
	*(t+1) = tag.time_stamp[1];
	*(t+2) = tag.time_stamp[0];
	*(t+3) = 0;

	t2 = time+t2;

	val = read(fd, &tag.time_stamp_extended, 1);
          

	if(t2 >= 3498000 )
	{
		printf("data size value%d\n",data_size);
		printf("reached time\n");
		exit(0);

	}

	else
	{

	val1 = write(fd1,&tag.previous_tag,4);
	val2 = write(fd1,&tag.type,1);
	val3 = write(fd1,&tag.data_size,3);
	val4 = write(fd1,&tag.time_stamp,3);
	val5 = write(fd1, &tag.time_stamp_extended, 1);
	val = read(fd,&tag.stream_id,3);
	val6 = write(fd1,&tag.stream_id,val);
		//printf("value=%d\n",val);

		if (data_size >= 400000)
		{
			printf("Trying to read more than buffer size data_size :%d\n", data_size);
			exit(1);
		}
		val = read(fd, buff, data_size);

		if (val >= 400000)
		{
			printf("Trying to read more than buffer size val :%d\n", val);
			exit(1);
		}
		val7 = write(fd1, buff, val);
		buff[val]='\0';

		printf("sum of time%d\n",t2); 
	   total1=val1+val2+val3+val4+val5+val6+val7+total1;
		printf("Total Number of byter write = %d\n",total1);
		return t2;

	}
}


