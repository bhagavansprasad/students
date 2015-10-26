#include "rpcc.h"
int aopen(char *p, int mode, int flags)
{
	int fd,len;
	fd=rpc_open(p, mode, flags);
	return fd;
}
int aread(int fd,char *b,int len )
{
	//int r;
	//r=
	return(rpc_read(fd,b,len));
	//return r;
}
int awrite(int r,char *b,int len )
{
	return (rpc_write(r,b,len));

}
int add(int a,int b)
{
	return(rpc_add(a,b));
}
int fact(int n)
{
	return(rpc_fact(n));
}
int addafter(int no)
{
	return(rpc_addafter(no));
}
int aclose(int fd)
{
	return(rpc_close(fd));
}
