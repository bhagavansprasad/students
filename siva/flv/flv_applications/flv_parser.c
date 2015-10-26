#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "flv1.h"
#include <fcntl.h>

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

	//printf("value=%d\n",val);
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
	unsigned char buff[40000];
	static int total1=0,total2=0;

	val = read(fd,&tag.previous_tag,4);
	val1 = write(fd1,&tag.previous_tag,val);
	val = read(fd,&tag.type,1);
	val2 = write(fd1,&tag.type,val);

	val = read(fd,&tag.data_size,3);
	val3 = write(fd1,&tag.data_size,val);
	
	c = (char *)&data_size;
	*c = tag.data_size[2];
	*(c+1) = tag.data_size[1];
	*(c+2) = tag.data_size[0];
	*(c+3) = 0;

	val = read(fd,&tag.time_stamp,3);
	val4 = write(fd1,&tag.time_stamp,val);

	t = (unsigned char *)&time;
	*t = tag.time_stamp[2];
	*(t+1) = tag.time_stamp[1];
	*(t+2) = tag.time_stamp[0];
	*(t+3) = 0;

	t2 = time+t2;

	val = read(fd, &tag.time_stamp_extended, 1);
	val5 = write(fd1, &tag.time_stamp_extended, val);
          
	total1=val1+val2+val3+val4+val5+total1;
	printf("before  time Total_1 number of bytes read =%d\n",total1);
	if(t2 >= 8000 )
	{
		printf("data size value%d\n",data_size);
		printf("reached time\n");
		exit(0);

	}

	else
	{

		val = read(fd,&tag.stream_id,3);
		val6 = write(fd1,&tag.stream_id,val);
		//printf("value=%d\n",val);

		if (data_size >= 20000)
		{
			printf("Trying to read more than buffer size data_size :%d\n", data_size);
			exit(1);
		}
		val = read(fd, buff, data_size);

		if (val >= 20000)
		{
			printf("Trying to read more than buffer size val :%d\n", val);
			exit(1);
		}
		val7 = write(fd1, buff, val);
		buff[val]='\0';

		printf("sum of time%d\n",t2); 

		total2=val6+val7+total2;
		printf("Total Number of byter read = %d\n",total2);
		return t2;

	}
}

	main()
	{
		int fd,fd1,fd2,t;
		static int i=0;
		flv_header hd;
		flv_tag tag;

	//	printf("SIZE OF HD =%d\n", sizeof(hd));
	//	printf("SIZE OF tag =%d\n", sizeof(tag));
		fd = open("sixth.flv",O_RDONLY);
		fd1 = open("f5.flv",O_CREAT|O_RDWR,0644);


		if (fd == -1 ) 
		{
			perror("file fd not opened because : \n");
			exit(0);
		}

		if (fd1 == -1)
		{
			perror("file not opened because : \n");
			exit(0);
		}

		write_header(fd,fd1,hd);
		t = write_tag(fd,fd1,tag);

		for(; t<=8000; )
		{
			printf("enter loop==%d\n",i++);
			t = write_tag(fd, fd1, tag);
		}
		printf("writing completed in 1.flv\n");


					
	}
