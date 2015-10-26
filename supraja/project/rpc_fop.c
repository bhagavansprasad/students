#include<stdio.h>
#include<fcntl.h>
#include "unistd.h"

int rpc_open(char * s,int flags,int mode)
{
	int fd = open(s,flags,mode);

	return fd;
}

int rpc_read(int t,char *buff,int l)
{
	int rval = read(t,buff,l);

	return rval;
}

int rpc_write(int t1,char * buff,int rval)
{     
	return write(t1,buff,rval);
}

int rpc_close(int t1)
{
	return close(t1);
}
