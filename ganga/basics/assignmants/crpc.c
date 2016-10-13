#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int crpc_open(char *fname, int mode, int flags)
{
	int fd = -1;

	//fd = open(fname, mode, flags);

	fd = rpc_foperations(fname, mode, flags);

	return fd;
}

int crpc_read(int fd1, char *buff,int size )
{
	int retval = 0;

	//	retval = read(fd1, buff, size);

	retval = rpc_foperations(fd1, buff, size);

	return retval;
}

int crpc_write(int fd2, char *buff,int size )
{
	int retval = -1 ;

	//	retval = write(fd2, buff, size);

	retval = rpc_foperations(fd2, buff, size);

	return retval;
}

int  crpc_lseek(int fd, off_t offset, int whence)
{
	int new_offset = -1 ;

	//	new_offset = lseek(fd1, offset, whence);

	new_offset = rpc_foperations(fd, offset, whence);

	return new_offset;
}

int crpc_close(int fd)
{
    rpc_foperations(fd);
	
	return close(fd);
}

