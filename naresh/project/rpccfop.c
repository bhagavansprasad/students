#include <fcntl.h>
#include "fcntl.h"
#include "rpccfop.h"
int rpcc_open(int ope,char * fname,int flag,int mode)
{
	int fd;
	fd = open(fname,flag,mode);
	return fd;
}

int rpcc_read(int fd,char *buff,int len)
{
	int r;
	r = read(fd,buff,len);
	return r;
}

int rpcc_write(int fd1,char *buff,int r)
{
	int w;
	w = write(fd1,buff,r);
	return w;
}

int rpcc_lseek(int fd,off_t k,int num)
{
	int l;
	l = lseek(fd,k,num);
	return l;
}

int rpcc_close(int fd)
{
	int t;
	t = close(fd);
	return t;
}
