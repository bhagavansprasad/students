#include<fcntl.h> 
#include "rpcc.h"
int aopen(char*p,int mode,int flag)
{
int fd,len;
fd=rpc_open(p,mode,len);
return fd;
}
int aread(int fd,char *b,int len )
{
int r;
r=rpc_read(fd,b,len);
return r;
}
int awrite(int r,char *b,int len )
{
int w;
w=rpc_write(r,b,len);
return w;
}
int aclose(int fd)
{
int x;
x=rpc_close(fd);
return x;
}
