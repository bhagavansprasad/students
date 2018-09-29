#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>	
#include <stdio.h>
#include "rpcc_fop.h"
#include "reply_struct.h"

int aopen(char *rfd, int flags, int mode)
{
	int fd = 0;
	fd = rpcc_open(rfd, flags, mode);
	return(fd);
}

int aread(int rfd, char *buff, int len)
{
	int rval = 0;
	rval = rpcc_read(rfd, buff, len);
	return(rval);
}

int awrite(int wfd, char *buff, int rretval)
{
	return rpcc_write(wfd, buff, rretval);
}

//int alseek(int rfd, off_t l, int pos)
//{
//return rpcc_lseek(rfd, l, pos);
//}

int aclose(int wfd)
{
	return rpcc_close(wfd);

}

