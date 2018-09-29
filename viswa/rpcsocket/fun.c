#include "rpc_fun.h"

int aopen(char *file , int mode , int flag )
{
	return rpc_open( file , mode , flag);
}


int aread(int fd , char *buff , int len)
{
	return rpc_read( fd , buff ,len);
}


int awrite(int fd , char *buff ,int len)
{
	return rpc_write( fd , buff , len);
}


int aclose(int fd)
{
	return rpc_close( fd );
}
