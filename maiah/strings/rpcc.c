#include <fcntl.h>
int rpcc_open(char *f,int m,int fl)
{
	int fd;
	fd=open(f,m,fl);
	return fd;
}
int rpcc_read(int fd,char *b,int l)
{
	int r;
	r=read(fd,b,l);
	return r;
}
int rpcc_write(int fd1,char *b,int num)
{
	int w;
	w=write(fd1,b,num);
	return w;
}
int rpcc_lseek(int fd,int p,int q)
{
	int k;
	k=lseek(fd,p,q);
	return k;
}
int rpcc_close(int fd)
{
	int t;
	t=close(fd);
	return t;
}
