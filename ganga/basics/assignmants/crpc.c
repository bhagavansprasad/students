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
	struct rpc_fop_data rpcdata;

	rpcdata.operation = CRPC_OPEN_REQ;
	strcpy(rpcdata.udata.odata.fname, fname);
	rpcdata.udata.odata.mode = mode;
	rpcdata.udata.odata.flags = flags;

	fd=rpc_foperations(&rpcdata);

	return fd ;
}

int crpc_read(int fd, char *buff, int size)
{
	int retval = -1 ;
	//struct rw_st un_data;

	union  rpcfop_un un_data;

	un_data.fd = fd;
	un_data.size = size;

	//retval = rpc_foperations(CRPC_READ_REQ, NULL, &rd_data, NULL, NULL, NULL);

	retval = rpc_foperations(CRPC_READ_REQ, &un_data);

	strcpy(buff, un_data.buff);

	return retval ;
}

int crpc_write(int fd,char *buff,int size)
{
	int retval = -1 ;
	//struct rw_st wd_data;

	union  rpcfop_un un_data;

	un_data.fd = fd;
	strcpy(un_data.buff, buff);
	un_data.size = size;

	//retval = rpc_foperations(CRPC_WRITE_REQ, NULL, NULL, &wd_data, NULL, NULL);

	retval = rpc_foperations(CRPC_WRITE_REQ, &un_data);

	return retval ;
}

int crpc_lseek(int fd, int off_set, int whence)
{
	int new_off_set = -1 ;
	//struct lseek_st ld_data;

	union  rpcfop_un un_data;

	un_data.fd = fd;
	un_data.off_set = off_set;
	un_data.whence = whence;

	//new_off_set = rpc_foperations(CRPC_LSEEK_REQ, NULL, NULL, NULL, &ld_data, NULL);

	new_off_set = rpc_foperations(CRPC_LSEEK_REQ, &un_data);

	return new_off_set;
}

int crpc_close(int fd)
{
	int cd = -1 ;
	//struct close_st cl_data;

	union  rpcfop_un un_data;

	un_data.fd = fd;

	//cd = rpc_foperations(CRPC_CLOSE_REQ, NULL, NULL, NULL, NULL, &cl_data);

	cd = rpc_foperations(CRPC_CLOSE_REQ, &un_data);

	return cd ;
}
