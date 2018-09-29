//#include <stdio.h>
int aopen(const char *str,int flags,int mode)
{
int fd,i;
fd=open(str,flags,mode);
return fd;
}
int aread(int fd,void *buff,int count)
{
int readval;
readval=read(fd,buff,count);
return readval;
}
int aclose(int fd)
{
close(fd);
}
int awrite(int fd,const char *buff,int count)
{
int writeval;
writeval=write(fd,buff,count);
return writeval;
}
int alseek(int fd,int offset,int whence)
{
int rtnlseek;
rtnlseek=lseek(fd,offset,whence);
return rtnlseek;
}


