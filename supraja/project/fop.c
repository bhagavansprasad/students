#include<stdio.h>
#include<fcntl.h>
#include "rpc_fop.h"

int aopen(char * s,int flags,int mode)
{
	int fd= rpc_open(s,flags,mode);

	return fd;
}

int aread(int t,char *buff,int l)
{
	int rval = rpc_read(t,buff,l);

	return rval;
}

int awrite(int t1,char * buff,int rval)
{     
	return rpc_write(t1,buff,rval);
}

int aclose(int t1)
{
	return rpc_close(t1);	
}
