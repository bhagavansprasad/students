#include "struct_req.h"
#include "struct_replay.h"
#include "rpcc_send_req.h"
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int retval = -1;

int rpcc_open(char *fn,int flags,int mode)
{
	struct final c_req;
	struct S_final reply;

	c_req.op = 1;
	strcpy(c_req.uni.a_open.fn ,fn);
	c_req.uni.a_open.flags = flags;
	c_req.uni.a_open.mode = mode;

	retval = rpcc_send_req(&c_req);
	printf("-->rpcc_send_req retval :%d\n", retval);

	retval = rpcc_read_req(&reply);
	printf("-->rpcc_read_req retval :%d\n", retval);
	printf("-->rpcc_read_req retval fd :%d\n",  reply.s_uni.s_open.fd);

	retval = reply.s_uni.s_open.fd;
	if(retval == -1)
		printf("in rpcc error is : %d\n",reply.s_uni.s_open.err_no);

	return retval;
}

int rpcc_read(int fd,char* buff,int len)
{
	struct final c_req;
	struct S_final reply;
	c_req.op = 2;
	strcpy(c_req.uni.a_read.buff ,buff);
	c_req.uni.a_read.fd = fd;
	c_req.uni.a_read.len = len;

	retval=	rpcc_send_req(&c_req);
	printf("-->rpcc_send_req retval :%d\n", retval);

	retval = rpcc_read_req(&reply);
	printf("-->rpcc_read_req retval :%d\n", retval);
	printf("rpcc_buffer:%s\n",reply.s_uni.s_read.buff);
	strcpy(buff,reply.s_uni.s_read.buff);


	retval=reply.s_uni.s_read.rval;

	return retval;
}
int rpcc_write(int fd, char *buff,int rval)
{
	struct final c_req;
	struct S_final reply;
	c_req.op = 3;
	strcpy(c_req.uni.a_write.buff ,buff);
	c_req.uni.a_write.fd = fd;
	c_req.uni.a_write.rval = rval;
	retval=rpcc_send_req(&c_req);
	printf("-->rpcc_send_req retval :%d\n", retval);
	retval = rpcc_read_req(&reply);
	printf("-->rpcc_read_req retval :%d\n", retval);
	strcpy(buff,c_req.uni.a_read.buff);
	retval=reply.s_uni.s_write.rval;
	return retval;
}
int rpcc_lseek(int fd, off_t l,int pos)
{
	struct final c_req;
	struct S_final reply;
	c_req.op = 4;
	c_req.uni.a_write.fd = fd;
	c_req.uni.a_lseek.l = l;
	c_req.uni.a_lseek.pos = pos;
	retval=	rpcc_send_req(&c_req);
	printf("-->rpcc_send_req retval :%d\n", retval);
	retval = rpcc_read_req(&reply);
	printf("-->rpcc_read_req retval :%d\n", retval);
	return(reply.s_uni.s_lseek.rval);
}
int rpcc_close(int fd)
{
	struct final c_req;
	struct S_final reply;
	c_req.op = 5;
	c_req.uni.a_close.fd = fd;
	retval=rpcc_send_req(&c_req);

	printf("-->rpcc_send_req retval :%d\n", retval);

	retval = rpcc_read_req(&reply);

	printf("-->rpcc_read_req retval :%d\n", retval);
	retval=reply.s_uni.s_close.rval;
	return retval;
}
