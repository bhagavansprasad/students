#include "stuct.h"
#include "struct_reply.h"
<<<<<<< rpcfop.c
#include "sendreq.h"
#include <stdio.h>
=======
#include "send.h"
>>>>>>> 1.2
int rpc_fop(struct student *stud)
{
	int fd;
	struct reply_final rep;

	fd = send_request( stud,  &rep );
	printf("send:%d\n",fd);
	return fd;

}
