#include "stdio.h"
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

	//fd = rpc_foperations(&rpcdata);

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));

	recv_rpcc_client_reply(&reply, sizeof(reply));

	printf("--> reply recieved : %d \n", reply.ureply.oreply.fd); 

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

	//retval = rpc_foperations(&rpcdata);

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));

	strcpy(buff, rpcdata.udata.rdata.buff);

	recv_rpcc_client_reply(&reply, sizeof(reply));

	printf("--> reply recieved : %d \n", reply.ureply.rreply.byte_count); 
	
	return reply.ureply.rreply.byte_count;
}

int crpc_write(int fd,char *buff,int size)
{
	int retval = -1 ;
	struct rpc_fop_data rpcdata;
	struct rpc_fop_data_reply reply ;

	rpcdata.operation = CRPC_WRITE_REQ;
	rpcdata.udata.wdata.fd = fd;
	strcpy(buff, rpcdata.udata.wdata.buff);
	rpcdata.udata.wdata.size = size;

	//retval = rpc_foperations(&rpcdata, sizeof(rpcdata));

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));

	recv_rpcc_client_reply(&reply, sizeof(reply));
	
	printf("--> reply recieved : %d \n", reply.ureply.wreply.byte_count); 
	
	return reply.ureply.wreply.byte_count ;
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

	//new_off_set = rpc_foperations(&rpcdata, sizeof(rpcdata));

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));

	recv_rpcc_client_reply(&reply, sizeof(reply));
	
	printf("--> reply recieved : %d \n", reply.ureply.sreply.new_off_set); 
	
	return reply.ureply.sreply.new_off_set ;
}

int crpc_close(int fd)
{
	int cd = -1 ;
	struct rpc_fop_data rpcdata;
	struct rpc_fop_data_reply reply ;

	rpcdata.udata.cdata.fd = fd;

	//cd= rpc_foperations(&rpcdata, sizeof(rpcdata));

	send_rpcc_client_request(&rpcdata, sizeof(rpcdata));

	recv_rpcc_client_reply(&reply, sizeof(reply));
	
	printf("--> reply recieved : %d \n", reply.ureply.creply.retval); 
	
	return reply.ureply.creply.retval ;
}
