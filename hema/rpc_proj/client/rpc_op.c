#include <stdio.h>
#include <unistd.h>
#include "string.h"
#include "../inc/rpc_op.h"

int fd,rval,wval,lval,t;
int rpc_open(char *filename, int mode, int flags)
{
	int fd;
	fope_struct fdata;
	fope_struct_reply reply;

	fdata.operation = RPC_OPEN;
	printf("-->C. RPC_OPEN: file:mode:flags: %s:%d:flags:%d\n", filename, mode, flags);
	strcpy(fdata.udata.opdata.filename, filename);
	fdata.udata.opdata.mode=mode;
	fdata.udata.opdata.flags=flags;

	c_rpc_send_request(&fdata);
	c_rpc_read_reply(&reply);

	printf("-->C. RPC_OPEN: reply fd:%d\n", reply.udata.op_reply.fd);

	return reply.udata.op_reply.fd;
}

int rpc_read(int fd,char *buff,int len)
{
	int rval;
	fope_struct fdata;
	fope_struct_reply reply;

	fdata.operation = RPC_READ;
	fdata.udata.rrdata.fd = fd;
	fdata.udata.rrdata.len = len;
	strcpy(buff,fdata.udata.rrdata.buff);
    //buff[buff,reply.udata.rr_reply.rval]='\0';
    //printf("--->c:buff:%s\n\n",buff);
	c_rpc_send_request(&fdata);
	c_rpc_read_reply(&reply);

	printf("-->C. RPC_READ: reply retval:%d\n", reply.udata.rr_reply.rval);

	return reply.udata.rr_reply.rval;
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
	printf("-->C. RPC_write: reply writeval:%d\n", reply.udata.wr_reply.wval);

	return reply.udata.wr_reply.wval;
}
off_t rpc_lseek(int fd, off_t filename,int whence)
{
	int lval;
	fope_struct fdata;
	fope_struct_reply reply;

	fdata.operation = RPC_LSEEK;
	fdata.udata.lsdata.fd=fd;
	fdata.udata.lsdata.filename=filename;
	fdata.udata.lsdata.whence = whence;

	c_rpc_send_request(&fdata);
	c_rpc_read_reply(&reply);
	printf("-->C. RPC_lseek: reply lval:%d\n", reply.udata.ls_reply.lval);

	return reply.udata.ls_reply.lval;

	//lval= rpc_fop(&fdata,&reply);
	
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
	printf("-->C. RPC_close: reply fd:%d\n", reply.udata.cl_reply.fd);

	return reply.udata.cl_reply.fd;

	//t=rpc_fop(&fdata,&reply);
	
}
