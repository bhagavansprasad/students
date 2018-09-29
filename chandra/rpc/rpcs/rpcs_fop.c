#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <bits/errno.h>
#include "req_struct.h"
#include "reply_struct.h"
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
struct rpcs reply;
//void server_send_data(struct rpcs *reply);

void rpcser_fop(struct rpcc *req, struct rpcs *reply)
{

	printf("operation is : %d\n", req -> op);
	switch(req -> op)
	{
		//	int errno;
		case 1 :
			printf("open a file:%s\n", req -> uni.a_open.fn);
			reply -> r_uni.r_open.fn = open(req -> uni.a_open.fn, req -> uni.a_open.flags, req -> uni.a_open.mode); 
			reply -> rop = req -> op;
			reply -> r_uni.r_open.err_no = errno;

			if(reply -> r_uni.r_open.fn == -1)
			{
				reply -> r_uni.r_open.err_no = errno;

				printf("----> structure error number is : %d\n", reply -> r_uni.r_open.err_no);
				printf("----> error number is : %d\n", errno);
				perror("----> error is : ");
			}
			printf("open success : %d\n", reply -> r_uni.r_open.fn);
			break;
		case 2 :
			printf("read a file : \n");
			reply -> r_uni.r_read.rfd = read(req -> uni.a_read.rfd, req -> uni.a_read.buff, req -> uni.a_read.len); 
			reply -> rop = req -> op;
			reply -> r_uni.r_read.buff[reply -> r_uni.r_read.rfd]='\0';
			strcpy(reply -> r_uni.r_read.buff, req -> uni.a_read.buff);
			printf("buffer : %s\n", req -> uni.a_read.buff);
			printf("buffer : %s\n", reply -> r_uni.r_read.buff);

			break;
		case 3 :
			printf("write a file : \n");
			reply -> r_uni.r_write.wfd = write(req -> uni.a_write.wfd, req -> uni.a_write.buff, req -> uni.a_write.rretval); 
			reply -> rop = req -> op;
			break;
//		case 4 : 
//			printf("lseek a file : \n");
//			reply -> r_uni.r_lseek.l = lseek(req -> uni.a_lseek.rfd, req -> uni.a_lseek.l, req -> uni.a_lseek.pos); 
//			reply -> rop = req -> op;
//			break;
		case 4 :
			printf("close a file : \n");
			reply -> r_uni.r_close.wfd = close(req -> uni.a_close.wfd); 
			reply -> rop = req -> op;

			if(reply -> r_uni.r_close.wfd == -1)
			{
				reply -> r_uni.r_close.err_no = errno;
			}
//				server_send_data(&reply);

			break;
		default : 
			printf("wrong operation\n");   
	}
}

