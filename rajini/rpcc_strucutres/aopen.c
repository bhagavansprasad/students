#include "fcntl.h"
#include "rpccfop.h"

int aopen(char * p,int mode,int flags)
{
	int fd;
	
	fd=rpcc_open(p,mode,flags);
	
	return fd;
}

int aread(int fd,char * buff,int len)
{
	int r;
	
	r=rpcc_read(fd, buff, len);
	
	return r;
}

int awrite(int fd1, char * buff,int r)
{
	int w;
	
	w=rpcc_write(fd1, buff, r);
	
	return w;
}

off_t alseek(int fd,off_t offset,int whence)
{
	int f;
	
	f=rpcc_lseek(fd, offset, whence);
	
	return f;
}

int aclose(int fd)
{
	int e;
	
	e=rpcc_close(fd);
	
	return e;
}
