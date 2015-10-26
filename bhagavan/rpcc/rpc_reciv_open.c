#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>


int s_open( char*pathname,int flags,int mode)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

	return open(pathname,flags, mode);
}

int s_read(int fd1,char* buff,int count)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

	return read(fd1,buff,count);	
}

int s_write(int fd2, char* buff,int count)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

	return write(fd2,buff,count);
}

int s_close(int fd)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

 	 return close(fd);
}

