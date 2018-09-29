#include <stdio.h>
#include <fcntl.h>
#include "struct.h"
int rpcc_fop(struct rpcc f)
{
	switch(f.op)
	{
		case 1:return(open(f.u.o.fn,f.u.o.flag,f.u.o.mode));
		case 2:return(read(f.u.r.fp,f.u.r.buff,f.u.r.len));
		case 3:return(write(f.u.w.fp,f.u.w.buff,f.u.w.len));
		case 4:return(close(f.u.c.fn));
		default:printf("wrong value \n");
	}
}
