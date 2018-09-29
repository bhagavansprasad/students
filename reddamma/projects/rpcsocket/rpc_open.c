#include "fcntl.h"
#include "stdio.h"
#include "string.h"
#include "rpc_open.h"
#define OPEN 1
#define READ 2
#define CLOSE 3
int rpc_open(char *s,int mode,int flags)
{
	int fd;
	struct open_data o;

	strcpy(o.s,s);
	o.mode=mode;
	o.flags=flags;
	
	fd=rpc_fop(OPEN,&o);

	return fd;
}

int rpc_read(int t,char *buff,int l)
{
	int rval;
	struct read_data r;

	r.t=t;
	strcpy(r.buff,buff);
	r.l=l;

	rval=rpc_fop(READ,&r);
	strcpy(buff,r.buff);
		
	return rval;
}

int rpc_close(int t)
{
	int t1;
	struct close_data c;
	c.t=t;

	t1=rpc_fop(CLOSE,&c);
	
	return t1;
}	
