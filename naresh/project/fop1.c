#include "fcntl.h"
#include "rpcc.h"
int aopen(char * fname,int flag,int mode)
{
	int fd;
	fd = rpcc_open(fname,flag,mode);
	return fd;
}

int aread(int fd,char * buff,int len)
{
	int r;
	r=rpcc_read(fd,buff,len);
	return r;
}

int awrite(int fd1,char * buff,int r)
{
	int w;
	w=rpcc_write(fd1,buff,r);
	return w;
}

int alseek(int fd,off_t k,int num)
{
	int l;
	l=rpcc_lseek(fd,k,num);
//	return l;
}

int aclose(int fd)
{
	int t;
	t=rpcc_close(fd);
	return t;
}
