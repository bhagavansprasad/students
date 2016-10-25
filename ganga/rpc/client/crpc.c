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

	//fd = rpc_foperations(&rpcdata);

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));

	return fd ;
}

int crpc_read(int fd, char *buff, int size)
{
	int retval = -1 ;
	struct rpc_fop_data rpcdata;

	rpcdata.operation = CRPC_READ_REQ;
	rpcdata.udata.rdata.fd = fd;
	rpcdata.udata.rdata.size = size;

	retval = rpc_foperations(&rpcdata);

	strcpy(buff, rpcdata.udata.rdata.buff);

	return retval ;
}

int crpc_write(int fd,char *buff,int size)
{
	int retval = -1 ;
	struct rpc_fop_data rpcdata;

	rpcdata.operation = CRPC_WRITE_REQ;
	rpcdata.udata.wdata.fd = fd;
	strcpy(buff, rpcdata.udata.wdata.buff);
	rpcdata.udata.wdata.size = size;

	retval = rpc_foperations(&rpcdata);

	return retval ;
}

int crpc_lseek(int fd, int off_set, int whence)
{
	int new_off_set = -1 ;
	struct rpc_fop_data rpcdata;

	rpcdata.operation = CRPC_LSEEK_REQ;
	rpcdata.udata.sdata.fd = fd;
	rpcdata.udata.sdata.off_set = off_set;
	rpcdata.udata.sdata.whence = whence;

	new_off_set = rpc_foperations(&rpcdata);

	return new_off_set;
}

int crpc_close(int fd)
{
	int cd = -1 ;
	struct rpc_fop_data rpcdata;

	rpcdata.udata.cdata.fd = fd;

	cd= rpc_foperations(&rpcdata);

	return cd ;
}
