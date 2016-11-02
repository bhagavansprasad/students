#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "string.h"
#include "../defs/rpc_fop.h"

int crpc_open(char *fname,int mode,int flags)
{
	int fd = -1 ;
	struct rpc_fop_data rpcdata;
	struct rpc_fop_data_reply reply ;

	rpcdata.operation = CRPC_OPEN_REQ;
	strcpy(rpcdata.udata.odata.fname, fname);
	rpcdata.udata.odata.mode = mode;
	rpcdata.udata.odata.flags = flags;

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));

	recv_rpcc_client_reply(&reply, sizeof(reply));

	printf("-->C: fd recieved :%d\n", reply.ureply.oreply.fd); 

	return reply.ureply.oreply.fd ;
}

int crpc_read(int fd, char *buff, int size)
{
	int retval = -1;
	struct rpc_fop_data rpcdata;
	struct rpc_fop_data_reply reply;

	rpcdata.operation = CRPC_READ_REQ;
	rpcdata.udata.rdata.fd = fd;
	rpcdata.udata.rdata.size = size;

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));
	strcpy(rpcdata.udata.rdata.buff, buff);

	recv_rpcc_client_reply(&reply, sizeof(reply));

	printf("-->C: retval recieved : %d \n", reply.ureply.rreply.retval); 
	printf("-->C: replied buffer  : %s \n", reply.ureply.rreply.buff); 
	
	strcpy(buff,reply.ureply.rreply.buff);
	return reply.ureply.rreply.retval;
}

int crpc_write(int fd,char *buff,int size)
{
	int retval = -1 ;
	struct rpc_fop_data rpcdata;
	struct rpc_fop_data_reply reply ;

	rpcdata.operation = CRPC_WRITE_REQ;
	rpcdata.udata.wdata.fd = fd;
	strcpy(rpcdata.udata.wdata.buff, buff);
	rpcdata.udata.wdata.size = size;

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));

	recv_rpcc_client_reply(&reply, sizeof(reply));
	
	printf("-->C: retval recieved : %d \n", reply.ureply.wreply.retval); 
	
	return reply.ureply.wreply.retval ;
}

int crpc_lseek(int fd, int off_set, int whence)
{
	int new_off_set = -1 ;
	struct rpc_fop_data rpcdata;
	struct rpc_fop_data_reply reply ;

	rpcdata.operation = CRPC_LSEEK_REQ;
	rpcdata.udata.sdata.fd = fd;
	rpcdata.udata.sdata.off_set = off_set;
	rpcdata.udata.sdata.whence = whence;

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));

	recv_rpcc_client_reply(&reply, sizeof(reply));
	
	printf("-->C: new_off_set recieved : %d \n", reply.ureply.sreply.new_off_set); 
	
	return reply.ureply.sreply.new_off_set ;
}

int crpc_close(int fd)
{
	int cd = -1 ;
	struct rpc_fop_data rpcdata;
	struct rpc_fop_data_reply reply ;

	rpcdata.operation = CRPC_CLOSE_REQ;
	rpcdata.udata.cdata.fd = fd;

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));

	recv_rpcc_client_reply(&reply, sizeof(reply));
	
	printf("-->C: fd recieved : %d \n", reply.ureply.creply.fd); 
	
	return reply.ureply.creply.fd ;
}
