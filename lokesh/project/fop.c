#include "fcntl.h"
#include "rpccfop.h"
#include "stdio.h"
int aopen(char *fname,int mode,int flag)
{ 
int fd;

fd=rpccopen(fname,mode,flag);

return fd;
}

int aread(int rfd,char*buff,int len)
{
int r;

r=rpccread(rfd,buff,len);

return r;
}
int awrite(int wfd,char *buff, int len)
{
int w;

w=rpccwrite(wfd,buff,len);
return w;
}
off_t alseek(int rfd,off_t offset,int whence)
{
off_t t;

t=rpcclseek(rfd,offset,whence);

return t;
}
int aclose(int fd)
{
int f;
f=rpccclose(fd);
return f;
}
