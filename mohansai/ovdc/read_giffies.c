#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"

int parse_and_store(char *buff)
{
	int i,word=0,k=0,count=0;
	char temp[10];
    //printf("im in parse_and_store fun\r\n");	
	for( i = 0 ; buff[i] != '\0' ; i++,k++)
	{
 	  // printf("im in if loop\r\n");	
		if(buff[i] != ' ')
		{
			//printf(" %c",temp[k]);
			temp[k]=buff[i];
		}
		else
		{
			// printf("im in else loop--%d\r\n",i);	
			word++;
			if(k!='0'&& word>=12 && word<=16)
			{
				temp[k] = '\0';
				printf("-->parse_and_store: %s\n\r",temp);
				//printf("the giffe %d",atoi(temp));
				count+= atoi(temp);
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
	
	sprintf(buffer,"/proc/%d/stat", pid);
	
	printf("-->buffer: %s\r\n", buffer);
	
	if((fs=open(buffer,O_RDONLY))==-1)
	{
		printf("error in open a file");
		exit(1);
	}
	retval=read(fs,buff,1024);
	
	buff[retval]='\0';
	
	printf("-->buff: %s\n\r",buff);

	total_number=parse_and_store(buff);

	return total_number;
}





