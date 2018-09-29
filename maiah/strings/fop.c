#include "fcntl.h"
#include "rpcc1.h"
int aopen(char *p,int m,int fl)
{
	int fd;
	fd=rpcc_open(p,m,fl);
	return fd;
}
int aread(int fd,char *b,int l)
{
	int r;
	r=rpcc_read(fd,b,l);
	return r;
}
int awrite(int fd1,char *b,int num)
{
	int w;
	w=rpcc_write(fd1,b,num);
	return w;
}
int alseek(int fd,int p,int q)
{
	int k;
	k=rpcc_lseek(fd,p,q);
	return k;
}
int aclose(int fd)
{
	int t;
	t=rpcc_close(fd);
	return t;
}
