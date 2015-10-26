#include<stdio.h>
#include "struct_req.h"

void debug_before_write(struct final *c_req)
{
	printf("operation:%d\n",c_req->op);

	switch(c_req->op)
	{
		case 1 :
			printf("fn:%s\n",c_req->uni.a_open.fn);
			printf("flags:%d\n",c_req->uni.a_open.flags);
			printf("mode:%d\n",c_req->uni.a_open.mode);

			break;
		case 2 :
			printf("d.fd:%d\n",c_req->uni.a_read.fd);
			printf("d.len:%d\n",c_req->uni.a_read.len);

			break;
		case 3 :
			printf("%d\n",c_req->uni.a_write.fd);
			printf("%s\n",c_req->uni.a_write.buff);
			printf("%d\n",c_req->uni.a_write.rval);

			break;
		case 4 : 
			printf("%d\n",c_req->uni.a_lseek.fd);
			printf("%d\n",(int )c_req->uni.a_lseek.l);
			printf("%d\n",c_req->uni.a_lseek.pos);
			break;
		case 5 :
			printf("%d\n",c_req->uni.a_close.fd);
			printf("%d\n",c_req->op);

			break;
		default : 
			printf("wrong operation\n");   
	}


}
