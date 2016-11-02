#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int aopen(char *s,int mode,int flags)
{
	int fd=rpc_open(s,mode,flags);
	return fd;
}
int aread(int fd,char *buff,int len)
{
	int rval=rpc_read(fd,buff,len);
	return rval;
}
int awrite(int fd,char *buff,int rval)
{
	int wval=rpc_write(fd,buff,rval);
	return wval;
}
int alseek(int fd,off_t s,int whence)
{
	int lval=rpc_lseek(fd,s,whence);
	return lval;
	
}
int aclose(int fd)
{
	int t=rpc_close(fd);
	return t;
}


