#include<fcntl.h> 
#include "rpcc.h"
int rpc_open(char*p,int mode,int flag)
{
int fd,len;
fd=open(p,mode,len);
return fd;
}
int rpc_read(int fd,char *b,int len )
{
int r;
r=read(fd,b,len);
return r;
}
int rpc_write(int r,char *b,int len )
{
int w;
w=write(r,b,len);
return w;
}
int rpc_close(int fd)
{
int x;
x=close(fd);
return x;
}
