#include <stdio.h>
#include <fcntl.h>
#include "rpc_op.h"
int rpc_fop(int i, struct open_data *op, struct read_data *rd, struct close_data *cls)
{
	int fd,rval,t1;
	switch (i)
	{	
		case 1:
			fd=open(op->s,op->mode,op->flags);
			return fd;
			break;	
		case 2:
			rval=read(rd->t,rd->buff,rd->l);
			return rval;
			break;

		case 3:
			t1=close(cls->t);
			return t1;
			break;

		default:
			printf("there is no file:");
			break;


	}
}
