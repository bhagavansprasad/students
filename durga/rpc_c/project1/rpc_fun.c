/*rpc_open function*/
int rpc_open(char *pathname, int mode, int flag)
{
	int fd;
	fd = open(pathname, mode,flag);
	return(fd);
}
/*rpc_read function*/

int rpc_read(int fd, char *buf,int len)
{
	int r;
	r = read(fd, buf,len);
	return(r);
}
/*rpc_write function*/
int rpc_write(int fd, char *buf, int len)
{
	int w;
	w = write(fd, buf,len);
	return(w);
}
/*function for lseek*/
int rpc_lseek( int fd, int offset, int whence)
{
	lseek(fd, offset, whence);
}
/*rpc_close function*/

int rpc_close(int fd)
{
	int fd1;
	fd1 = close(fd);
	return(fd1);
}

