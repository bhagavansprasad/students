#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "errno.h"

main()
{
	int fd,j=0,k=0,flag=1;

	//	static int i;

	char buffer[2048] = "Hello world",buffer1[100];

	int retval=0,wrretval=0 ,count=0;

	//	printf("argc=%d \r\n",argc);	

	if((fd = open("/dev/chardev", O_RDWR, 0)) == -1) 	
	{
		perror("error in opening a file for reading ");
		exit(1);
	}
	else
		printf("open file sucessfully\n");

	printf("-->fd :%d\n", fd);

	retval = write(fd, buffer, strlen(buffer));

	printf("-->errno :%d, retval :%d\n", errno, retval);
	/*
	   retval = read(fd, buffer, 100);
	   printf("%d\n\n",retval);
	   printf("%s\n\n\n\n", buffer);
	   buffer[retval] = '\0';

	   if(write(fd , buffer1 , j)==-1) 
	   {
	   perror("destinatiom file failed to open");
	   exit(1);
	   }
	 */
	close(fd);
}
