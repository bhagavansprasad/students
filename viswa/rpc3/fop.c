int  aopen( char  *file, int flag, int mode)
{
	int fd;
	fd=rpc_open(file,flag,mode);
	return fd;
}

int aread( int file, char *buff, int len)
{
	int fd;
	fd = rpc_read(file,buff,len);
	return fd;
}
int awrite( int file, char *buff, int len)
{
	int fd;
	fd = rpc_write( file, buff, len);
	return  fd;
}
int aclose(int f)
{
rpc_close( f);
return 0;
}
