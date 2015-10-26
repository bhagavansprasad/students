#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>	
#include <stdio.h>
#include "rpc_fop.h"

int aopen(char *rfd, int flags, int mode)
{
	int fd = 0;
	fd = rpc_open(rfd, flags, mode);
	return(fd);
}

int aread(int rfd, char *buff, int len)
{
	int rval = 0;
	rval = rpc_read(rfd, buff, len);
	return(rval);
}

int awrite(int wfd, char *buff, int rretval)
{
	return rpc_write(wfd, buff, rretval);
}

int alseek(int rfd, off_t offset, int whence)
{
    return rpc_lseek(rfd, offset, whence);
}

int aclose(int wfd)
{
	return rpc_close(wfd);

}

