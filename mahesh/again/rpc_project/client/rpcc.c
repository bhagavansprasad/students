#include "struct_req.h"
#include "struct_rply.h"
#include "rpcc_send_req.h"
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void rpcc_send_req(struct final *c_req, struct S_final *s_rply);
void client_read_req(struct S_final *s_rply);
int rpcc_open(char *fn,int flags,int mode)
{
	struct final c_req;
	struct S_final s_rply;
	c_req.op = 1;
	strcpy(c_req.uni.a_open.fn ,fn);
	c_req.uni.a_open.flags = flags;
	c_req.uni.a_open.mode = mode;
	rpcc_send_req(&c_req,&s_rply);
	client_read_req(&s_rply);
	int rval = s_rply.s_uni.s_open.fd;
	if(rval == -1)
		printf("in rpcc error is : %d\n",s_rply.s_uni.s_open.err_no);
	return rval;
	//return(s_rply.s_uni.s_open.fd);
}
int rpcc_read(int fd,char* buff,int len)
{
	struct final c_req;
	struct S_final s_rply;
	c_req.op = 2;
	//strcpy(c_req.uni.a_read.buff ,buff);
	c_req.uni.a_read.fd = fd;
	c_req.uni.a_read.len = len;
	rpcc_send_req(&c_req,&s_rply);
	client_read_req(&s_rply);
	strcpy(buff,s_rply.s_uni.s_read.buff);
	buff[s_rply.s_uni.s_read.rval] = '\0';
	printf("in rpcc buff is : %s\n",buff);
	printf("in rpcc fd is : %d\n",s_rply.s_uni.s_read.rval);
	return(s_rply.s_uni.s_read.rval);
}
int rpcc_write(int fd, char *buff,int rval)
{
	struct final c_req;
	struct S_final s_rply;
	c_req.op = 3;
	strcpy(c_req.uni.a_write.buff ,buff);
	c_req.uni.a_write.fd = fd;
	c_req.uni.a_write.rval = rval;
	rpcc_send_req(&c_req,&s_rply);
	client_read_req(&s_rply);
	return(s_rply.s_uni.s_write.rval);
}
int rpcc_lseek(int fd, off_t l,int pos)
{
	struct final c_req;
	struct S_final s_rply;
	c_req.op = 4;
	c_req.uni.a_write.fd = fd;
	c_req.uni.a_lseek.l = l;
	c_req.uni.a_lseek.pos = pos;
	rpcc_send_req(&c_req,&s_rply);
	client_read_req(&s_rply);
	return(s_rply.s_uni.s_lseek.rval);
}
int rpcc_close(int fd)
{
	struct final c_req;
	struct S_final s_rply;
	c_req.op = 5;
	c_req.uni.a_close.fd = fd;
	rpcc_send_req(&c_req,&s_rply);
	client_read_req(&s_rply);
	return(s_rply.s_uni.s_close.rval);
}
int rpcc_get_first()
{
	struct final c_req;
	struct S_final s_rply;
	c_req.op = 6;
	//c_req.uni.a_ = fd;
	rpcc_send_req(&c_req,&s_rply);
	client_read_req(&s_rply);
	return(s_rply.s_uni.s_first.rval);
}
int rpcc_get_prev(int val)
{
	struct final c_req;
	struct S_final s_rply;
	c_req.op = 7;
	c_req.uni.a_prev.val = val;
	rpcc_send_req(&c_req,&s_rply);
	client_read_req(&s_rply);
	return(s_rply.s_uni.s_prev.rval);
}
int rpcc_get_next(int val)
{
	struct final c_req;
	struct S_final s_rply;
	c_req.op = 8;
	c_req.uni.a_next.val = val;
	rpcc_send_req(&c_req,&s_rply);
	client_read_req(&s_rply);
	return(s_rply.s_uni.s_next.rval);
}
int rpcc_get_last()
{
	struct final c_req;
	struct S_final s_rply;
	c_req.op = 9;
	//c_req.uni.a_ = fd;
	rpcc_send_req(&c_req,&s_rply);
	client_read_req(&s_rply);
	return(s_rply.s_uni.s_last.rval);
}
int rpcc_get_fact(int val1, int val2, int val3)
{
	struct final c_req;
	struct S_final s_rply;
	c_req.op = 10;
	c_req.uni.a_fact.val1 = val1;
	c_req.uni.a_fact.val2 = val2;
	c_req.uni.a_fact.val3 = val3;
	rpcc_send_req(&c_req,&s_rply);
	client_read_req(&s_rply);
	return(s_rply.s_uni.s_fact.rval);
}
