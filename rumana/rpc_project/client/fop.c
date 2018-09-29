#include"rpcc.h"
int aopen(char *p,int mode,int flags)
{
	int fd=rpc_open(p,mode,flags);
	return(fd);
}
int aread(int fd,char *b,int len)
{
	int fd1=rpc_read(fd,b,len);
	return(fd1);
}
int awrite(int r,char *b,int len)
{
	return(rpc_write(r,b,len));
}
int aclose(int fd)
{
	return(rpc_close(fd));
}

