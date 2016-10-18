#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "string.h"
#include "rpc_fop.h"

int crpc_open(char *fname,int mode,int flags)
{
	int fd = -1 ;
	struct open_st op_data;

	strcpy(op_data.fname, fname);
	op_data.mode=mode;
	op_data.flags=flags;

	fd=rpc_foperations(CRPC_OPEN_REQ, &op_data);

	return fd ;
}

int crpc_read(int fd,char *buff,int size)
{
	int retval = -1 ;
	struct read_st rd_data;

	rd_data.fd = fd;
	strcpy(rd_data.buff, buff);
	rd_data.size = size;

	retval = rpc_foperations(CRPC_READ_REQ, &rd_data);

	return retval ;
}

int crpc_write(int fd,char *buff,int size)
{
	int retval = -1 ;
	struct write_st wd_data;

	wd_data.fd = fd;
	strcpy(wd_data.buff, buff);
	wd_data.size = size;

	retval = rpc_foperations(CRPC_WRITE_REQ, &wd_data);

	return retval ;
}

int crpc_lseek(int fd, int off_set, int whence)
{
	int new_off_set = -1 ;
	struct lseek_st ld_data;

	ld_data.fd = fd;
	ld_data.off_set = off_set;
	ld_data.whence = whence;

	new_off_set = rpc_foperations(CRPC_LSEEK_REQ, &ld_data);

	return new_off_set;
}

int crpc_close(int fd)
{
	int cd = -1 ;
	struct close_st cl_data;

	cl_data.fd = fd;

	cd = rpc_foperations(CRPC_CLOSE_REQ, &cl_data);

	return cd ;
}
