#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "rpc_fop.h"
#include <string.h>
#include "rpc_send_req.h"
#include "rpcc_fop.h"
int  rpc_open( char *rfd, int flags, int mode)
{
	struct rpcc data;
	struct rpcs reply;
	data.op = 1;
	data.u.o.flags = flags;
	data.u.o.mode = mode;
	strcpy(data.u.o.rfd, rfd);
	int fd = rpcc_fop(&data, &reply);
	return fd;
}

int rpc_read( int rfd, char *buff, int len)
{
	struct rpcc data;
	struct rpcs reply;
	data.op = 2;
	data.u.r.rfd = rfd;
	data.u.r.len = len;
	//strcpy(data.u.r.buff, buff);

	int rval = rpcc_fop(&data, &reply);
	strcpy(buff, data.u.r.buff);

	return rval;
}


int rpc_write( int wfd, char *buff, int rretval)
{	
	struct rpcc data;
	struct rpcs reply;
	data.op = 3;
	data.u.w.wfd = wfd;
	data.u.w.rretval = rretval;
	strcpy(data.u.w.buff, buff);

	return rpcc_fop(&data, &reply);

}

int rpc_lseek(int rfd , off_t offset, int whence)
{
    struct rpcc data;
	struct rpcs reply;
	data.op = 4;
	data.u.l.rfd = rfd;
	data.u.l.offset = offset;
	data.u.l.whence = whence;

	return rpcc_fop(&data, &reply);
}

int rpc_close(int wfd)
{	
	struct rpcc data;
	struct rpcs reply;
	data.op = 5;
	data.u.c.wfd = wfd;

	return rpcc_fop(&data, &reply);
}

