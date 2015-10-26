#include "fcntl.h"
#include "rpccfop.h"
int rpcc_open(char * p,int mode,int flag)
{
	int fd;
	fd=open(p,mode,flag);
	return fd;
}
int rpcc_read(int fd,char * buff,int len)
{
	int r;
	r=read(fd,buff,len);
	return r;
}
int rpcc_write(int fd1, char * buff,int r)
{
	int w;
	w=write(fd1,buff,r);
	return w;
}
int rpcc_lseek(int fd,int len,int num)
{
	int f;
	f=lseek(fd,len,num);
	return f;
}
int rpcc_close(int fd)
{
	int e;
	e=close(fd);
	return e;
}
