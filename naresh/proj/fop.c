#include "fcntl.c"
#include "fop.h"
int aopen(char * fname,int flag,int mode)
{
int fd;
fd=rpcc_open(fname,flag,mode);
return fd;
}

int aread(int fd,char * buff,int len)
{
int r;
r= rpcc_read(fd,buff,len);
return r;
}

int aclose(int fd)
{
int t;
t=rpcc_close(fd);
return t;
}
