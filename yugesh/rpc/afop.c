#include <stdio.h>
#include <fcntl.h>
#include "sys/types.h"
#include "sys/stat.h"
#include<unistd.h>
	int aopen(char* file,int mode,int flag)
	{
	    int fd1;
		fd1=open(file,mode,flag);
		return fd1;
	}
	int aread(int file,char* mode,int flag)
	{
	    int rv;
		rv=read(file,mode,flag);
		return rv;
	}
	int awrite(int file,char* mode,int flag)
	{
	int vr;
		vr=write(file,mode,flag);
		return vr;
	}
int aclose(int fd)
{
return close(fd); 
}



