#include <stdio.h>
int rpc_open(char *file, int flag, int mode)
{
	int fd;
	fd= open( file, flag, mode);
	return fd;
}
int rpc_read( int file, char *buff, int len)
{
	int fd;
	fd = read( file, buff, len);
	return fd;
}
int rpc_write( int file, char *buff, int len)
{
	int fd;
	fd = write( file, buff, len);
	return fd;
}
int rpc_close(int file)
{
	int fd;
	fd =close(file);
	return(0);
}

