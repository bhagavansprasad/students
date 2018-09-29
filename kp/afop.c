#include<stdio.h>
#include<fcntl.h>
int aopen(char*fname,int flags)
{
	int fd;
	fd=open(fname,flags);
	return fd;
}
int aread(int fd,char*buff,size_t count)
{
	int r;
	r=read(fd,buff,count);
	return r;
}
int awrite(int fd,char*buff,size_t count)
{
	int w;
	w=write(fd,buff,count);
	return w;
}
int alseek(int fd,off_t offset,int whence)
{
int l;
l=lseek(fd,offset,whence);
return l;
}
int aclose(int fd)
{
close(fd);
}
