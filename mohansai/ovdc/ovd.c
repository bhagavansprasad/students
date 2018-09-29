#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "string.h"
#include "ovdc.h"

#define MAX 10
//#define DEBUG 

int parse_and_store(char *buff)
{
	int i,word=0,k=0,count=0;
	char temp[10];
	for( i = 0 ; buff[i] != '\0' ; i++,k++)
	{
		if(buff[i] != ' ')
		{
			temp[k]=buff[i];
		}
		else
		{
			word++;
			if(k!='0' && word >= 12 && word <= 16)
			{
				temp[k] = '\0';
				count+= atoi(temp);// convert the string to integer  and add the pid
			}
			k=-1;
		}
	}
	return count;
}

int get_giffies_by_pid(int pid)
{
	char  buffer[1024],buff[1024];
	int fs, retval=0,total_number=0;

#ifdef DEBUG
	printf("-->ovd: get_giffies_by_pid :%d\r\n", pid);
#endif
	
	sprintf(buffer,"/proc/%d/stat", pid);
#ifdef DEBUG
	printf("piderror--> %s\n\r",buffer);
#endif

	if ((fs = open(buffer,O_RDONLY)) < 0)
	{
		return -1;
	}

	
	retval = read(fs, buff, 1024);

	buff[retval] = '\0';

	total_number = parse_and_store(buff);

	close(fs);

	return total_number;
}

void ovd(int write_fd, int pid)
{
#ifdef DEBUG
	printf("this is ovd");
#endif
	
	int ret, i;
	ovdc_data data;

	data.pid = pid;

	if ((data.gifs = get_giffies_by_pid(pid)) < 0)
		return;

	ret = write(write_fd, &data, sizeof(data));

#ifdef DEBUG
	printf("-->ovd: %5d-%5d\r\n", data.pid, data.gifs);
#endif
	if(ret == -1)
	{
		perror("write syscal failed:\r\n");
		return;
	}
}
