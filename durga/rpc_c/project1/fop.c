#include "rpc_c.h"
/*function for aopen*/

int aopen( char *pathname, int mode, int flag)
{
	int fd;
	fd = rpc_open( pathname, mode, flag);
	return(fd);
}
/*function for read*/
int aread( int fd, char *buf, int len)
{
	int r;
	r = rpc_read( fd, buf, len);
	return(r);
}
/*function for write*/
int awrite( int fd, char*buf, int len)
{
	int w;
	w = rpc_write( fd, buf, len);
	return(w);
}
/*function for lseek*/
int alseek(int fd, int offset, int whence)
{
	rpc_lseek(fd, offset, whence);

}
/*function for close*/
int aclose( int fd)
{
	int fd1;
	fd1 = rpc_close( fd);
	return(fd1);
}



