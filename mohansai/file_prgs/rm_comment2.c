#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main( int argc , char *argv[])
{
	int fs,fd,i,j=0,flag=0;

	char buffer[512];
	char count = 0;
	int retval = 0,total = 0;

	printf("argc = %d \r\n",argc);	
	if (argc < 3)
	{
		printf("Invalid arguments\r\n");
		exit(1);
	}
	if((fs=open(argv[1], O_RDONLY, 0)) == -1) 	
	{
		printf("error in opening a file for reading :%s\r\n", argv[1]);
		exit(1);
	}
	if ((fd = creat(argv[2], 0644)) == -1)
	{
		perror("error in opening file");
		printf("error in opening a file for read and write :%s\r\n", argv[2]);
		exit(1);
	}

	while(1)
	{
		
		retval = read(fs, buffer, 255);
		printf("the return value  = %d\r\n",retval);
		total = total + retval;
		printf("the total value  = %d\r\n",total);
		buffer[retval] = '\0';

		for(i=0 ; i < retval ; i++)
		{ 
			if(flag == 0)
			{	
				if(buffer[i]=='/' && buffer[i+1]=='*')
				{
					count++;
					flag=1;
					printf("count increment = %2d \r\n",count);
				}
			}		
			else
			{
				if(buffer[i]=='*' && buffer[i+1]=='/')
				{
					count--;
					printf("count decrement = %2d \r \n",count);
					flag=0;
					i= i + 2;
				}	
			}

			if(flag == 0 && count<=0 )
			{
				write(fd, &buffer[i], 1);
			}

		}	

		if(retval < 255)
			break;
	}	

	close(fs);
	close(fd);
}

