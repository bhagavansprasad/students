#include "fcntl.h"
#include "stdio.h"
#include "string.h"
#include "rpc_op.h"

int fd,rval,wval,lval,t;
int rpc_open(char *filename, int mode, int flags)
{
	int fd;
	fope_struct fdata;
	fope_struct_reply reply;

	fdata.operation = RPC_OPEN;
	strcpy(fdata.udata.opdata.filename, filename);
	fdata.udata.opdata.mode=mode;
	fdata.udata.opdata.flags=flags;

	c_rpc_send_request(&fdata);
	c_rpc_read_reply(&reply);

	//fd=rpc_fop(&fdata, &reply);
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

	c_rpc_send_request(&fdata);
	c_rpc_read_reply(&reply);

	//rval=rpc_fop(&fdata,&reply);

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

	c_rpc_send_request(&fdata);
	c_rpc_read_reply(&reply);

	//wval=rpc_fop(&fdata,&reply);
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

	c_rpc_send_request(&fdata);
	c_rpc_read_reply(&reply);

	//lval= rpc_fop(&fdata,&reply);
	return 0;
}

int rpc_close(int fd)
{
	int t;
	fope_struct fdata;
	fope_struct_reply reply;

	fdata.operation = RPC_CLOSE;
	fdata.udata.cldata.fd=fd;

	c_rpc_send_request(&fdata);
	c_rpc_read_reply(&reply);

	//t=rpc_fop(&fdata,&reply);
	return 0;
}
