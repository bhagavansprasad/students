#include <stdio.h>
#include <fcntl.h>
#include "rpcc.h"
int aopen(char *p, int mode, int flag)
{
	int fd,len;
	fd=rpcc_open(p,mode,flag);
	return fd;
}
int aread(int fd, char *buff, int len)
{
	int r;
	r=rpcc_read(fd,buff,len);
	return r;
}
int awrite(int fd, char *buff, int len)
{
	int w;
	w=rpcc_write(fd,buff,len);
	return w;
}
off_t alseek(int fd, off_t p,int qr)
{
	int ls;
	ls=rpcc_lseek(fd,p,qr);
	return ls;
}
int aclose(int fd)
{
	int cl;
	cl=rpcc_close(fd);
	return cl;
}
