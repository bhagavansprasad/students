
#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "req_struct.h"
#include <string.h>
#include "rpc_send_req.h"
#include "reply_struct.h"

int retval = -1;

int  rpcc_open( char *fn, int flags, int mode)
{
	int retval;
	struct rpcc req;
	struct rpcs reply;
	req.op = 1;
	req.uni.a_open.flags = flags;
	req.uni.a_open.mode = mode;
	strcpy(req.uni.a_open.fn, fn);

	retval = rpc_send_req(&req);
	printf("rpc_send_req retval is : %d\n", retval);

	retval = rpc_read_req(&reply);
//	printf("rpc_read_req retval is : %d\n", retval);
	printf("rpc_recv_req retval fd is : %d\n", reply.r_uni.r_open.fn);

	int fd = reply.r_uni.r_open.fn;
	if(fd == -1)
		printf("in rpcc error is : %d\n", reply.r_uni.r_open.err_no);
	return fd;
}

int rpcc_read( int rfd, char *buff, int len)
{
	struct rpcc req;
	struct rpcs reply;
	req.op = 2;
	req.uni.a_read.rfd = rfd;
	req.uni.a_read.len = len;
	strcpy(req.uni.a_read.buff, buff);

	retval = rpc_send_req(&req);
	printf("rpc_send_req retval is : %d\n", retval);

	retval = rpc_read_req(&reply);
	printf("rpc_read_req retval is : %d\n", retval);
	printf("rpc_buffer : %s\n", reply.r_uni.r_read.buff);
		strcpy(buff, req.uni.a_read.buff);

	return(reply.r_uni.r_read.rfd);
}


int rpcc_write( int wfd, char *buff, int rretval)
{	
	struct rpcc req;
	struct rpcs reply;
	req.op = 3;
	req.uni.a_write.wfd = wfd;
	req.uni.a_write.rretval = rretval;
	strcpy(req.uni.a_write.buff, buff);

	retval = rpc_send_req(&req);
	printf("rpc_send_req retval is : %d\n", retval);
	retval = rpc_read_req(&reply);
	printf("rpc_read_req retval is : %d\n", retval);
	strcpy(buff, req.uni.a_write.buff);

	return(reply.r_uni.r_write.wfd);

}

/*int rpcc_lseek(int rfd, off_t l, int pos)
  {
  struct rpcc req;
  struct rpcs reply;
  req.op = 4;
  req.uni.a_lseek.rfd = rfd;
  req.uni.a_lseek.l = l;
  req.uni.a_lseek.pos = pos;

  retval = rpc_send_req(&req);
  printf("rpc_send_req retval is : %d\n", retval);
  retval = rpc_read_req(&reply);
  printf("rpc_read_req retval is : %d\n", retval);

  return(reply.r_uni.r_lseek.l);
  }*/

int rpcc_close(int wfd)
{	
	struct rpcc req;
	struct rpcs reply;
	req.op = 4;
	req.uni.a_close.wfd = wfd;

	retval = rpc_send_req(&req);
	printf("rpc_send_req retval is : %d\n", retval);
	retval = rpc_read_req(&reply);
	printf("rpc_read_req retval is : %d\n", retval);

	return(reply.r_uni.r_close.wfd);
}

