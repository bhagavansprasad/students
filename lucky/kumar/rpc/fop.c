#include <sys/stat.h>
#include <unistd.h>
#include "rpcc.h"

int aopen(char *pathname, int mode, int flags)
{
	int fd;
	fd = rpcc_open(pathname, mode, flags);
    return fd;
}

int aread(int fd, char *buf, int count)
{
	int r;

	r = rpcc_read(fd,buf,count);

	return r;
}

int awrite(int fd, char *buf, int count)
{
	int w;
	w=rpcc_write(fd,buf,count);
	return w;
}

int alseek(int fd, int offset, int whence)
{
	int q;
	q=rpcc_lseek(fd,offset,whence);
	return q;
}

int aclose(int fd)
{
	int c;
	c=rpcc_close(fd);
	return c;
}
