#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rpc_fop.h"


int crpc_open(char *fname, int mode, int flags)
{
	int fd = -1 ;

	fd = rpc_foperations(CRPC_OPEN_REQ, fname, mode, flags, 0, NULL, 0, 0);

	return fd;
}

int crpc_read(int fd, char *buff, int size )
{
	int retval = -1 ;

	retval = rpc_foperations(CRPC_READ_REQ, NULL, 0, 0, fd, buff, size, 0);

	return retval;
}

int crpc_write(int fd, char *buff, int size )
{ 
	int retval = -1 ;

	retval = rpc_foperations(CRPC_WRITE_REQ, NULL, 0, 0, fd, buff, size, 0);

	return retval;
}

int  crpc_lseek(int fd, off_t offset, int whence)
{
	int new_offset = -1 ;

	new_offset = rpc_foperations(CRPC_LSEEK_REQ, NULL, 0, 0, fd, NULL, offset, whence);

	return new_offset;

}

int crpc_close(int fd)
{
	int retval = rpc_foperations(CRPC_CLOSE_REQ, NULL, 0, 0, fd, NULL, 0, 0);

	return retval;
}
