#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "rpcc_fp.h"

int rpc_open(char *fn,int flag, int mode)
{
	struct rpcc f;

	f.op=1;
	f.u.o.flag=flag;
	f.u.o.mode=mode;
	strcpy(f.u.o.fn,fn);
	int rval=rpcc_fop( f);
	return rval;
}

int rpc_read(int fp,char *buff,int len)
{
	struct rpcc f;

	f.op=2;
	f.u.r.fp=fp;
	f.u.r.len=len;
	strcpy(f.u.r.buff,buff);
	return rpcc_fop(f);
}

int rpc_write(int fp,char *buff,int len)
{
	struct rpcc f;

	f.op=3;
	f.u.w.fp=fp;
	f.u.w.len=len;
	strcpy(f.u.w.buff,buff);
	return rpcc_fop(f);
}

int rpc_close(int fn)
{
	struct rpcc f;

	f.u.c.fn=fn;
	return rpcc_fop(f);
	
}
