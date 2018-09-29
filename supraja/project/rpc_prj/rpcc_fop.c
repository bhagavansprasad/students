#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "struct_replay.h"
#include "struct_req.h"
#include <sys/types.h>
#include <unistd.h>

void rpcs_fop(struct final *c_req,struct S_final *s_rply)
{
	printf("operation is : %d\n",c_req->op);
	switch(c_req->op)
	{
		case 1 :
			s_rply->s_uni.s_open.fd	= open(c_req->uni.a_open.fn,c_req->uni.a_open.flags, c_req->uni.a_open.mode); 
			s_rply->s_op = c_req->op;
			//printf("in case operation is : %d\n",s_rply->s_op);
			if(s_rply->s_uni.s_open.fd == -1)
			{
				s_rply->s_uni.s_open.err_no = errno;
				printf("----> structure error number is : %d\n",s_rply->s_uni.s_open.err_no);
				printf("----> error number is : %d\n",errno);
				perror("----> error is : ");
			}
			break;
		case 2 :
			s_rply->s_uni.s_read.rval = read(c_req->uni.a_read.fd,c_req->uni.a_read.buff,c_req->uni.a_read.len); 
			s_rply->s_op = c_req->op;
			break;
		case 3 :
			s_rply->s_uni.s_write.rval = write(c_req->uni.a_write.fd,c_req->uni.a_write.buff, c_req->uni.a_write.rval); 
			s_rply->s_op = c_req->op;
			break;
		case 4 : 
			s_rply->s_uni.s_lseek.rval =lseek(c_req->uni.a_lseek.fd,c_req->uni.a_lseek.l, c_req->uni.a_lseek.pos); 
			s_rply->s_op = c_req->op;
			break;
		case 5 :
			s_rply->s_uni.s_close.rval = close(c_req->uni.a_close.fd); 
			s_rply->s_op = c_req->op;

			if(s_rply->s_uni.s_close.rval == -1)
			{
				s_rply->s_uni.s_close.err_no = errno;
			}
			break;
		default : 
			printf("wrong operation\n");   
	}
}
