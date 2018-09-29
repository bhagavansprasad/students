#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main( int argc , char *argv[])
{
	int fs,fd,j=0,k=0,flag=1;

	static int i;

	char buffer[2048],buffer1[100];

	int retval=0,wrretval=0 ,count=0;

	printf("argc=%d \r\n",argc);	

	if((fs=open(argv[1], O_RDONLY, 0)) == -1) 	
	{
		printf("error in opening a file for reading :%s\r\n", argv[1]);
		exit(1);
	}

	if ((fd = creat(argv[2], 644)) == -1)
	{
		perror("error in opening file");
		printf("error in opening a file for read and write :%s\r\n", argv[2]);
		exit(1);
	}


	while(1)
	{
		printf("count=%d",count);
		retval = read(fs, buffer, 100);
		printf("%d\n\n",retval);
		printf("%s\n\n\n\n", buffer);
		buffer[retval] = '\0';

		for(i=0;buffer[i]!='\0';i++)
		{	
			if(buffer[i]=='/' && buffer[i+1]=='*')
				flag=0;

			if(buffer[i]=='*' && buffer[i+1]=='/')
			{
				i=i+2;
				flag=1;
			}

			if(flag==1)
			{
				buffer1[j]=buffer[i];
				j++;		
			}
		}

		buffer1[j]='\0';	

		if(write(fd , buffer1 , j)==-1) 
		{
		perror("destinatiom file failed to open");
		exit(1);
		}

		printf("%s\n\n\n\n", buffer1);
		if(retval<100)
			break;
	}	
	close(fs);
	close(fd);
}
