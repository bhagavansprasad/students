#include "fcntl.h"
#include "stdio.h"
#include "rpcc_fop.h"
int rpcc_open(char *p,int m,int fl)
{
	int fd;
	fd=rpcc_fop(1,0,NULL,0,p,m,fl,0);
	return fd;
}
int rpcc_read(int fd,char *b,int l)
{
	int r;
	r=rpcc_fop(2,fd,b,l,NULL,0,0,0);
	return r;
}
int rpcc_write(int fd,char *b,int l)
{
	int w;
	w=rpcc_fop(3,fd,b,l,NULL,0,0,0);
	return w;
}
int rpcc_lseek(int fd,int l,int y )
{
	int ls;
	ls=rpcc_fop(4,fd,NULL,l,NULL,0,0,y);
	return ls;
}
int rpcc_close(int fd)
{
	int t;
	t=rpcc_fop(5,fd,NULL,0,NULL,0,0,0);
	return t;
}
