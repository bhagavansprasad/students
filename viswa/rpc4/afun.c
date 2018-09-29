#include <stdio.h>
#include "rpcfun.h"
int  aopen( char  *file, int flag, int mode)
{
		int fd=0;

		fd=rpc_open( file, flag, mode);
		printf("fd_aopen=%d\n",fd);
		return fd;
}

int aread( int file, char *buff, int len)
{
		int fd=0;
		fd= rpc_read( file, buff, len);
		printf("fd_aread=%d\n",fd);
		return fd;
}
int awrite( int file, char *buff, int len)
{
	int fd=0;
 	fd=rpc_write( file, buff, len);
		printf("fd_awrite=%d\n",fd);
		return fd;
}
int aclose(int f)
{
return rpc_close( f);
}
