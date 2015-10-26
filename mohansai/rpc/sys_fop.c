#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "file_db.h"
#include "stdlib.h"
#include "string.h"


int sum=0;
int count =0;
int sys_open(char *filename, int mode)
{
	int fd;

	if((fd = open(filename, mode, 0644)) == -1)
		perror("error in open a file");

	return fd;
}

int sys_read(char *rbuff, int len, file_info *fcb)
{
	int retval,fd;	

	fd = sys_open(fcb->name, fcb->mode);

	lseek(fd, sum, SEEK_SET);
	
	if ((retval = read(fd, rbuff, len)) < 0 )
			perror("Error in reading file");
		
	sum=sum+len;	
	return retval; 
}	

int sys_write(char *rbuff, int len, file_info *fcb)
{
	int retval,fd;
	
	fd = sys_open(fcb->name, fcb->mode);
	retval = lseek(fd, count, SEEK_SET);
	printf("mode   :%d\n", fcb->mode);
	printf("count  :%d\n", count);
	printf("count  :%d\n", count);
	printf("Retval :%d\n", retval);
	printf("len    :%d\n", len);
	printf("rbuff  :%s\n", rbuff);


	if ((retval = write(fd, rbuff, len)) < 0)
		perror("Error in writing file");

	printf("write retval :%d\n", retval);

	count=count+retval;

	sys_close(fd);
	return retval; 
}	


int sys_close(int fd)
{
	int retval;
	if ((retval = close(fd)) < 0)
		perror("Error in closing file");
	file_remove(fd);	
	return retval;
}
