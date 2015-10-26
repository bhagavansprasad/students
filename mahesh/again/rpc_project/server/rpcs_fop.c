#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "struct_rply.h"
#include "struct_req.h"
#include <sys/types.h>
#include <unistd.h>

void server_send_data(struct S_final *s_rply);
struct S_final s_rply;
void rpcs_fop(struct final *c_req)
{
	printf("operation is : %d\n",c_req->op);
	switch(c_req->op)
	{
		case 1 :	
			printf("-----> opening a file <-----\n");
			s_rply.s_uni.s_open.fd	= open(c_req->uni.a_open.fn,c_req->uni.a_open.flags, c_req->uni.a_open.mode); 
			s_rply.s_op = c_req->op;
			//printf("in case operation is : %d\n",s_rply->s_op);
			if(s_rply.s_uni.s_open.fd == -1)
			{
				s_rply.s_uni.s_open.err_no = errno;
				printf("----> structure error number is : %d\n",s_rply.s_uni.s_open.err_no);
				printf("----> error number is : %d\n",errno);
				perror("----> error is : ");
			}
			server_send_data(&s_rply);
			break;
		case 2 :
			printf("-----> reading from a file <-----\n");
			s_rply.s_uni.s_read.rval = read(c_req->uni.a_read.fd,c_req->uni.a_read.buff,c_req->uni.a_read.len); 
			s_rply.s_op = c_req->op;
			strcpy(s_rply.s_uni.s_read.buff, c_req->uni.a_read.buff );
			server_send_data(&s_rply);
			break;
		case 3 :
			printf("-----> writing to a file <-----\n");
			s_rply.s_uni.s_write.rval = write(c_req->uni.a_write.fd,c_req->uni.a_write.buff, c_req->uni.a_write.rval); 
			s_rply.s_op = c_req->op;
			server_send_data(&s_rply);
			break;
		case 4 : 
			printf("----->  doing lseek operation <-----\n");
			s_rply.s_uni.s_lseek.rval =lseek(c_req->uni.a_lseek.fd,c_req->uni.a_lseek.l, c_req->uni.a_lseek.pos); 
			s_rply.s_op = c_req->op;
			server_send_data(&s_rply);
			break;
		case 5 :
			printf("-----> closing a file <-----\n");
			s_rply.s_uni.s_close.rval = close(c_req->uni.a_close.fd); 
			s_rply.s_op = c_req->op;

			if(s_rply.s_uni.s_close.rval == -1)
			{
				s_rply.s_uni.s_close.err_no = errno;
			}
			server_send_data(&s_rply);
			break;
		case 6 :
			printf("-----> get first <-----\n");
			s_rply.s_uni.s_first.rval = get_first(); 
			s_rply.s_op = c_req->op;
			server_send_data(&s_rply);
			break;
		case 7 :
			printf("-----> get prev <-----\n");
			s_rply.s_uni.s_prev.rval = get_prev(c_req->uni.a_prev.val); 
			s_rply.s_op = c_req->op;
			server_send_data(&s_rply);
			break;
		case 8 :
			printf("-----> get next <-----\n");
			s_rply.s_uni.s_next.rval = get_next(c_req->uni.a_next.val); 
			s_rply.s_op = c_req->op;
			server_send_data(&s_rply);
			break;
		case 9 :
			printf("-----> get last <-----\n");
			s_rply.s_uni.s_last.rval = get_last(); 
			s_rply.s_op = c_req->op;
			server_send_data(&s_rply);
			break;
		case 10 :
			printf("-----> get fact <-----\n");
			s_rply.s_uni.s_fact.rval = get_fact(c_req->uni.a_fact.val1,c_req->uni.a_fact.val2, c_req->uni.a_fact.val3); 
			s_rply.s_op = c_req->op;
			server_send_data(&s_rply);
			break;
		default : 
			printf("wrong operation\n");   
	}
}
