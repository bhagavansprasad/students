#include "fcntl.h"
#include "stdio.h"
#include "string.h"
#include "rpc_op.h"
int fd,rval,wval,lval,t;
int rpc_open(char *s,int mode,int flags)
{
	int fd;
	fope_struct fdata;
	fope_struct_reply reply;

	fdata.operation = RPC_OPEN;
	strcpy(fdata.udata.opdata.s,s);
	fdata.udata.opdata.mode=mode;
	fdata.udata.opdata.flags=flags;

	fd=rpc_fop(&fdata, &reply);
	return 0;
}

int rpc_read(int fd,char *buff,int len)
{
	int rval;
	fope_struct fdata;
	fope_struct_reply reply;

	fdata.operation = RPC_READ;
	fdata.udata.rrdata.fd=fd;
	fdata.udata.rrdata.len=len;
	strcpy(buff,fdata.udata.rrdata.buff);

	rval=rpc_fop(&fdata,&reply);

	return 0;
}
int rpc_write(int fd,char *buff,int rval)
{

	int wval;
	fope_struct fdata;
	fope_struct_reply reply;


	fdata.operation = RPC_WRITE;
	fdata.udata.wrdata.fd=fd;
	fdata.udata.wrdata.rval=rval;
	strcpy(fdata.udata.wrdata.buff,buff);

	wval=rpc_fop(&fdata,&reply);
	return 0;
}
int rpc_lseek(int fd,off_t s,int whence)
{
	int lval;
	fope_struct fdata;
	fope_struct_reply reply;

	fdata.operation = RPC_LSEEK;
	fdata.udata.lsdata.fd=fd;
	fdata.udata.lsdata.s=s;
	fdata.udata.lsdata.whence = whence;

	lval= rpc_fop(&fdata,&reply);
	return 0;
}

int rpc_close(int fd)
{
	int t;
	fope_struct fdata;
	fope_struct_reply reply;

	fdata.operation = RPC_CLOSE;
	fdata.udata.cldata.fd=fd;
	t=rpc_fop(&fdata,&reply);
	return 0;
}
