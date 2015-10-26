#include "stdio.h"
#include "fcntl.h"
#include "rpccfop1.h"
int rpcc_open(char *p,int m,int f)
{
	int fd;
	fd=rpcc_fop(1,0,NULL,0,p,m,f,0);
	return fd;
}
int rpcc_read(int fd,char * buff,int len)
{
	int r;
	r=rpcc_fop(2,fd,buff,len,NULL,0,0,0);
	return r;
}
int rpcc_write(int fd1,char * buff,int len)
{
	int w;
	w=rpcc_fop(3,fd1,buff,len,NULL,0,0,0);
	return w;
}
int rpcc_lseek(int fd,int len,int y)
{
	int f;
	f=rpcc_fop(4,fd,NULL,len,NULL,0,0,y);
	return f;
}
int rpcc_close(int fd)
{
	int e;
	e=rpcc_fop(5,fd,NULL,0,NULL,0,0,0);
	return e;
}

