#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "fop.h"
int aopen(char *pathname, int flags, int mode)
{
	int fd=0;
	fd=rpccopen(pathname,flags,mode);
	return fd;
}
int aread(int fd, char *buff, int len)
{
	int r=0;
	r=rpccread(fd, buff, len);
	return r;
}
int awrite(int fd,char *buff, int len)
{
	int w=0;
	w=rpccwrite(fd, buff, len);
	return w;
}
int alseek(int fd, int offset, int whence)
{
	int l=0;
	l=rpcclseek(fd, offset, whence);
	return l;
}
int aclose(int fd)
{
	int c=0;
	c=rpccclose(fd);
	return c;
}
