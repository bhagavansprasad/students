#include "fcntl.h"
int aopen(char *fname,int mode,int flag)
{
int fd;
fd=open(fname,mode,flag);
return fd;
}
int aread(int fd,char *p,int l)
{
int r;
r=read(fd,p,l);
return r;
}
int awrite(int fd1,char *p,int r)
{
int w;
w=write(fd1,p,r);
return wint rpccclose(int fd1);
}
int alseek(int fd,int l,int num)
{
int t;
t=lseek(fd,l,num);
return t;
}
int aclose(int fd)
{
int f;
f=close(fd);
return f;
}
