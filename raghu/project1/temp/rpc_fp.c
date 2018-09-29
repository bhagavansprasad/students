#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "rpcc_fp.h"

/*open funtion*/
int rpc_open(char *fn, int flag, int mode)
{
	struct rpcc data;
	int retval = 0;

	data.op = 1;
	strcpy(data.u.o.fn, fn);
	data.u.o.flag = flag;
	data.u.o.mode = mode;

	retval = rpcc_fop(&data);

	return retval;
}

/*read function*/
int rpc_read(int fd, char *buff, int len)
{
	struct rpcc data;
	int retval = 0;

	data.op= 2;
	data.u.r.fd=fd;
	data.u.r.len=len;

	//TODO: No point in copying empty buffer
	//strcpy(data.u.r.buff, buff);

	rval = rpcc_fop(&data);
	strcpy(buff, data.u.r.buff);
	return rval;
}

/*write function*/
int rpc_write(int fd, char *buff, int len)
{
	struct rpcc f;

	f.op = 3;
	f.u.w.fd=fd;
	f.u.w.len=len;
	strcpy(f.u.w.buff, buff);
	return rpcc_fop(&f);
}

/*close function*/
int rpc_close(int fd)
{
	struct rpcc f;
	f.op = 4;
	f.u.c.fd = fd;
	return rpcc_fop(&f);
	
}
