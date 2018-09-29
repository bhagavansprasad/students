//int aopen(char *s,int flags,int mode)
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fop.h"

int aopen(const char *pathname, int flags, mode_t mode)
{
	int fd=0;

	fd = open(pathname, flags, mode);

	return fd;
}

//int aread(int p,char *buff,int count)
size_t aread(int fd, void *buf, size_t count)
{
	int r=0;

	r = read(fd, buf, count);

	return r;
}

int awrite(int q,char *buff,int r)
{
	int w=0;

	w = write(q,buff,r);

	return w;
}

int aclose(int fd)
{
	return close(fd);
}


