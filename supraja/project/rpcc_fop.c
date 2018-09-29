#include<stdio.h>
#include<fcntl.h>
#include <string.h>
#include "rpc1.h"
int rpcc_fop(struct rpcc *a )
{
	int  fd, rval;
	printf("operation :%d\n",a->op);
	switch (a->op)
	{
        case 1:
			 fd = open(a->u.o.s,a->u.o.flags,a->u.o.mode);
			 return fd;
              
        case 2:
			 rval = read(a->u.r.t,a->u.r.buff,a->u.r.l);
			// printf("%s\n",a->u.r.buff);
			return rval;

        case 3:
			 write(a->u.w.t1,a->u.w.buff,a->u.w.rval);
			break;

        case 4:
			 close(a->u.c.t1);
			break;

		default:
			printf("can not open file");
			
	}
}	
