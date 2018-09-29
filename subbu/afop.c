#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/start.h>
	int aopen(char* pathname,int flags,int mode)
	{
		int fd;
		fd=open(pathname,flags,mode);
		return fd;
	}
	int aread(int fd1,int buff,int count)
	{
		int retval;
		retval=read(fd1,buff,count);
		return retval;
	}
	int awrite(int fd2,int buff,int count)
	{
		int retval;
		retval=awrite(fd2,buffer,count)
			ret retval;
	}
	int aclose(int fd)
	{
		return close(fd);
	}	

