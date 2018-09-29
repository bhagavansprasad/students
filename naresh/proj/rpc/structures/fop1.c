#include <stdio.h>
#include "fcntl.h"
#include "rpcc.h"
#include "struct.h"

int aopen(char *fname,int flag,int mode)
{
	int fd;
	fd = rpcc_open(fname,flag,mode);
	printf("rpcc fd=---->%d\n",fd);

	return fd;
}

int aread(int fd,char * buff,int len)
{
	int r;
	r=rpcc_read(fd,buff,len);
	printf("rpcc r=---->%d\n",r);
	return r;
}

int awrite(int fd1,char * buff,int r)
{
	int w;
	w=rpcc_write(fd1,buff,r);
	printf("rpcc w=---->%d\n",w);
	return w;
}

off_t alseek(int fd,off_t k,int num)
{
	off_t l;
	l=rpcc_lseek(fd,k,num);
	printf("rpcc lseek=---->%d\n",l);
	
	return l;
}

int aclose(int fd)
{
	int t;
	t=rpcc_close(fd);

	return t;
}
