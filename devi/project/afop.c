#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "afop.h"
int aopen(const char *pathname, int flags, mode_t mode)
{
	int fd;
	fd=rpcc_open(pathname,flags,mode);
	return fd;
}
ssize_t aread(int fd, void *buf, size_t count)
{
	int fd1;
	fd1=rpcc_read(fd,buf,count);
	return fd1;
}
ssize_t awrite(int fd,const void *buf, size_t count)
{
	int i;
	i=rpcc_write(fd,buf,count);
	//printf("IN aopen buff val is %s\n", buf);
	return i;
}
off_t alseek(int fd, off_t offset, int whence)
{
	int i;
	i=rpcc_lseek(fd,offset,whence);
	return i;
}
int aclose(int fd)
{
	int i;
	i=rpcc_close(fd);
	return i;
}

