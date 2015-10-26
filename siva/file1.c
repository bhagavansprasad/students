#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
main()
{
	char buff[20];
	int fd,len;
	fd=open("es.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("file is not there\n");
	  	
            exit(1);
	}
        
	 
	len=read(fd,buff,10);
	buff[len + 1] = '\0';
	printf("%d\n",len);
	printf("%s\n",buff);
	printf("%d\n",fd);
	close(fd);
}

