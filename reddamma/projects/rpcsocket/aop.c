#include <stdio.h>
#include <fcntl.h>

int aopen(char *s,int mode,int flags)
{
	int fd=rpc_open(s,mode,flags);
	return fd;
}

int aread(int t,char * buff,int l)
{
	int rval=rpc_read(t,buff,l);
	return rval;
}

int aclose(int t)
{
	int t1=rpc_close(t);
	return t1;
}



