#include "fcntl.h"
#include "rpccfop.h"
int aopen(char * p,int mode,int flag)
{
	int fd;
	fd=rpcc_open(p,mode,flag);
	return fd;
}
int aread(int fd,char * buff,int len)
{
	int r;
	r=rpcc_read(fd,buff,len);
	return r;
}
int awrite(int fd1, char * buff,int r)
{
	int w;
	w=rpcc_write(fd1,buff,r);
	return w;
}
int alseek(int fd,int len,int num)
{
	int f;
	f=rpcc_lseek(fd,len,num);
	return f;
}
int aclose(int fd)
{
	int e;
	e=rpcc_close(fd);
	return e;
}
