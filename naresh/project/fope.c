#include "stdio.h"
#include "fcntl.h"
{
int rpcc_fope(int,char *,int,int,int,int,int,int,char *)
{
if(ope == 1)
{
int fd;
fd = open(fname,flag,mode);
return fd;
}
else if(ope == 2)
{
int r;
r = read(fd,buff,len);
return r;
}
else if(ope == 3)
{
int w;
w = write(fd1,buff,len);
return w;
}
else if(ope == 4)
{
int l;
l = lseek(fd,k,num);
return l;
}
else (fd)
{
int t;
t = close(fd);
return t;
}
}
