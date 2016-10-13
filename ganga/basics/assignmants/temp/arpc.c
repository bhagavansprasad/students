#include <unistd.h>
#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int aopen(char *fname, int mode, int flags)
{
	int fd = -1;

	fd = crpc_open(fname, mode, flags);

	return fd;
}

int aread(int fd1, char *buff,int size )
{
	int retval = -1;

	retval = crpc_read(fd1, buff, size);

	return retval;
}

int awrite(int fd2, char *buff,int size )
{
	int retval = -1 ;

	retval = crpc_write(fd2, buff, size);

	return retval;
}

int  alseek(int fd, off_t offset, int whence)
{
	int new_offset = -1 ;

	new_offset = crpc_lseek(fd, offset, whence);

	return new_offset;
}

int aclose (int fd)
{
	crpc_close(fd);

	return close(fd);
}
