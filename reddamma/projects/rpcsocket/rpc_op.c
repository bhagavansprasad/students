#include "fcntl.h"
#include "stdio.h"
#include "string.h"
#include "rpc_op.h"
#define OPEN 1
#define READ 2
#define CLOSE 3

int rpc_open(char *s,int mode,int flags)
{
	int fd;
	struct open_data op;
	strcpy(op.s,s);
	op.mode=mode;
	op.flags=flags;
	
	fd=rpc_fop(OPEN,&op,NULL,NULL);

	return fd;
}

int rpc_read(int t,char *buff,int l)
{
	int rval;
	struct read_data rd;
	rd.t=t;
	strcpy(rd.buff,buff);
	rd.l=l;

	rval=rpc_fop(READ,NULL,&rd,NULL);
	strcpy(buff,rd.buff);
		
	return rval;
}


int rpc_close(int t)
{
	int t1;
	struct close_data cls;
	cls.t=t;

	t1=rpc_fop(CLOSE,NULL,NULL,&cls);
	
	return t1;
}	
