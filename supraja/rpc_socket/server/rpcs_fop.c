#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "struct_replay.h"
#include "struct_req.h"
#include <sys/types.h>
#include <unistd.h>
void rpcs_fop(struct S_final *preply, struct final *c_req)
{
	printf("%d %s \n ",__LINE__,__FILE__);

	printf("operation is : %d\n",c_req->op);
	switch(c_req->op)
	{
		case 1:
			printf("-->opening a file :%s\n", c_req->uni.a_open.fn);
			preply->s_uni.s_open.fd	= open(c_req->uni.a_open.fn, c_req->uni.a_open.flags, c_req->uni.a_open.mode); 
			preply->s_op = c_req->op;
			preply->s_uni.s_open.err_no = errno;
			if(preply->s_uni.s_open.fd == -1)
			{
				preply->s_uni.s_open.err_no = errno;
				printf("--> structure error number is : %d\n",preply->s_uni.s_open.err_no);
				printf("--> error number is : %d\n",errno);
				perror("--> error is : ");
			}
			printf("-->open success :%d\n", preply->s_uni.s_open.fd);
			break;
		case 2 :
			printf("------>:read a file:\n");
			preply->s_uni.s_read.rval = read(c_req->uni.a_read.fd,c_req->uni.a_read.buff,c_req->uni.a_read.len); 
			preply->s_op = c_req->op;
			preply->s_uni.s_read.buff[preply->s_uni.s_read.rval]='\0';
			strcpy(preply->s_uni.s_read.buff,c_req->uni.a_read.buff);
			printf("------->buffer:%s\n",c_req->uni.a_read.buff);
			printf("------->buffer:%s\n",preply->s_uni.s_read.buff);
			break;
		case 3 :
			printf("--->write a file:\n");
			preply->s_uni.s_write.rval = write(c_req->uni.a_write.fd,c_req->uni.a_write.buff, c_req->uni.a_write.rval); 
			preply->s_op = c_req->op;
			break;
		case 4 : 
			printf("---->lseek a file:\n");
			preply->s_uni.s_lseek.rval =lseek(c_req->uni.a_lseek.fd,c_req->uni.a_lseek.l, c_req->uni.a_lseek.pos); 
			preply->s_op = c_req->op;
			break;
		case 5 :
			printf("------>close a file:\n");
			preply->s_uni.s_close.rval = close(c_req->uni.a_close.fd); 
			preply->s_op = c_req->op;

			if(preply->s_uni.s_close.rval == -1)
			{
				preply->s_uni.s_close.err_no = errno;
			}
			break;
		default : 
			printf("wrong operation\n");   
	}
}
