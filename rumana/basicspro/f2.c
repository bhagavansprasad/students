#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int aopen(char *name,int mode,int flag)
{
  int fd;
  fd=open("name",mode,flag);
  return(fd);
}

int aread(int fd,char *buff,int len)
{ 
	int r;
	r=read(fd,buff,len);
	return(r);
}

int awrite(int fd,char *buff,int len1)
{ 
	int w;
	w=write(fd,buff,len1);
	return(w);
}

int aclose(int fd)
{
	return(close(fd));
}

