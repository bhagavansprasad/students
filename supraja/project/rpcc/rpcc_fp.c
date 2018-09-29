#include <stdio.h>
#include <fcntl.h>
#include "rpc_fp.h"

int rpcc_fop(struct rpcc data)
{
	switch(data.op)
	{
		case 1:return(open(data.u.o.fn, data.u.o.flag, data.u.o.mode));
		case 2:return(read(data.u.r.fp,data.u.r.buff,data.u.r.len));
		case 3:return(write(data.u.w.fp,data.u.w.buff,data.u.w.len));
		case 4:return(close(data.u.c.fn));
		default:printf("wrong value \n");
	}
}
