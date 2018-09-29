#include"rpcc.h"
int aopen(char*p,int mode,int flags)
{
	int fd ,len;
	fd=rpc_open(p,mode,flags);
	return fd;
}
int aread(int fd,char*b,int len)
{
	return (rpc_read (fd,b,len));
}
int awrite(int r,char*b,int len)
{
	return(rpc_write(r,b,len);
			}
			int aclose(int fd)
			{
			return (rpc_close(fd));
			}


