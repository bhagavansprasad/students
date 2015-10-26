#include "fcntl.h"
int rpcc_fope(int i,char *fn,int fl,int mo,int len,int k,int n,int fd,int fd1,char *b)
{
	if(i == 1)
	{
		int fd;
		fd = open(fn,fl,mo);
		return fd;
	}
	else if(i == 2)
	{
		int r;
		r = read(fd,b,len);
		return r;
	}
	else if(i == 3)
	{
		int w;
		w = write(fd1,b,len);
		return w;
	}
	else if(i == 4)
	{
		int l;
		l = lseek(fd,k,n);
		return l;
	}
	else 
	{
		int t;
		t = close(fd);
		return t;
	}
}
