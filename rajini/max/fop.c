#include "fcntl.h"
#include "defs.h"
int aopen(char * p,int mode ,int flag)
{
	int fd;
	fd=open(p,mode,flag);
	return fd;
}
int aread(int fd,char * buff,int max)
{
	int r;
	r=read(fd,buff,max);
	return r;
}
int awrite(int fd1,char * buff,int r)
{
	int w;
	w=write(fd1,buff,r);
	return w;
}
int alseek(int fd,int max,int num)
{
	int f;
	f=lseek(fd,max,num);
	return f;
}
int aclose(int fd)
{
	int t;
	t=close(fd);
	return t;
}

