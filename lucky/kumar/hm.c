#include<sys/stat.h>
#include<unistd.h>
#include "string.h"
#include "comm_defs.h"
#include "structdefs.h"
#include "op.h"
int rpccopen(char *pathname, int flags, int mode)
{
	int fd=0;
    union rpc u1;	
	strcpy(u1.o1.pathname,pathname);
	u1.o1.flags=flags;
	u1.o1.mode=mode;
	fd=rpcfop(open,&u1);
	return fd;
}
int rpccread(int fd, char *buf, int count)
{
	int r=0;
    union rpc u1;	
	u1.r1.fd=fd;
	strcpy(buf,u1.r1.buf);
	u1.r1.count=count;
	r=rpcfop(read,&u1);
	return r;
}
int rpccwrite(int fd, char *buf, int count)
{
	int w=0;
    union rpc u1;	
	u1.w1.fd=fd;
	strcpy(buf,u1.w1.buf);
	u1.w1.count=count;
	w=rpcfop(write,&u1);
	return w;
}
int rpcclseek(int fd, int offset, int whence)
{
	int l=0;
    union rpc u1;	
	u1.l1.fd=fd;
	u1.l1.offset=offset;
	u1.l1.whence=whence;
	l=rpcfop(lseek,&u1);
	return l;
}
int rpccclose(int fd)
{
	int c=0;
    union rpc u1;	
	u1.c1.fd=fd;
	c=rpcfop(close,&u1);
	return c;
}
