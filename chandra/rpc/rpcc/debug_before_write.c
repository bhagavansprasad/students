#include<stdio.h>
#include "req_struct.h"

void debug_before_write(struct rpcc *req)
{
	printf("operation:%d\n", req -> op);

	switch(req -> op)
	{
		case 1 :
			printf("rfd:%s\n", req -> uni.a_open.fn);
			printf("flags:%d\n", req -> uni.a_open.flags);
			printf("mode:%d\n", req -> uni.a_open.mode);

			break;
		case 2 :
			printf("%d\n", req -> uni.a_read.rfd);
			//	printf("%d\n", req -> uni.a_read.buff);
			printf("%d\n", req -> uni.a_read.len);

			break;
		case 3 :
			printf("%d\n", req -> uni.a_write.wfd);
			printf("%s\n", req -> uni.a_write.buff);
			printf("%d\n", req -> uni.a_write.rretval);

			break;
		case 4 : 
			printf("%d\n", req -> uni.a_lseek.rfd);
			printf("%d\n", req -> uni.a_lseek.l);
			printf("%d\n", req -> uni.a_lseek.pos);
			break;
		case 5 :
			printf("%d\n", req -> uni.a_close.wfd);
			printf("%d\n", req -> op);

			break;
		default : 
			printf("wrong operation\n");   
	}


}
