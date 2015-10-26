#include<fcntl.h>
/* function for opening a file*/

int aopen(char *pathname, int mode, int flag)
{
	int fd1;
	fd1 = open( pathname, mode, flag);
	return(fd1);
}

/* function for read a file*/

int aread(int fd, char *buf, int len)
{
	int r;
	r = read( fd, buf, len);
	return(r);
}

/* function for write a file*/

int awrite(int fd,char *buf, int len)
{
	int w;
	w = write( fd, buf, len);
	return(w);
}

/* function for creat a file*/

int acreat(char *pathname, int mode)
{
	int fd1;
	fd1 = creat( pathname, mode);
	return(fd1);
}


/* function for close a file*/

int aclose(int fd)
{
	int fd1;
	fd1 = close( fd);
	return(fd1);
}
