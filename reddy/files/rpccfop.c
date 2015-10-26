#include "fcntl.h"
int rpcc open(char *fname,int mode,int flag)
{
int fd;
fd=open(fname,mode,flag);
return fd;
}
int rpcc read(int fd,char *p,int l)
{
int r;
r=read(fd,p,l);
return r;
}
int rpcc write(int fd1,char *p,int r)
{
int w;
w=write(fd,p,r);
return w;
}
int rpcclseek(int fd,int k,int num)
{
int t;
t=lseek(fd,k,num);
return t;
}
int rpccclose(int fd1)
{
int f;
f=close(fd1);
deturn f;
}

