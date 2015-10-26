#include<sys/stat.h>
#include<unistd.h>
#include "hm.h"
int aopen( char *pathname, int flags, int mode)
{
	int fd=0;
	fd=rpccopen(pathname,flags,mode);
	return fd;
}
int aread(int fd, char *buf, int count)
{
	int r=0;
	r=rpccread(fd,buf,count);
	return r;
}
int awrite(int fd, char *buf, int count)
{
	int w=0;
	w=rpccwrite(fd,buf,count);
	return w;
}
int alseek(int fd, int offset, int whence)
{
	int l=0;
	l=rpcclseek(fd,offset,whence);
	return l;
}
int aclose(int fd)
{
	int c=0;
	c=rpccclose(fd);
	return c;
}
