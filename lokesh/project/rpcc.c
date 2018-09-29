#include "fcntl.h"
#include "rpcc.h"
int rpcc_open(char *fname,int flag,int mode)
{ 
int fd;
fd=open(fname,flag,mode);
return fd;
}
int rpcc_read(int fd,char*buff,int len)
{
int r;
r=read(fd,buff,len);
return r;
}
int rpcc_close(int fd)
{
int t;
t=close(fd);
return t;
}
