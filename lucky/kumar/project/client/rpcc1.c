#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "fop.h"
int aopen(const char *pathname, int flags, mode_t mode)
{
	int fd=0;
	fd=rpccopen(pathname,flags,mode);
	return fd;
}
ssize_t aread(int fd, void *buf, size_t count)
{
	int r=0;
	r=rpccread(fd, buf, count);
	return r;
}
ssize_t awrite(int fd,void *buf, size_t count)
{
	int w=0;
	w=rpccwrite(fd, buf, count);
	return w;
}
off_t alseek(int fd, off_t offset, int whence)
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
