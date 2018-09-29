int rpc_open(char *filename, int flag, int mode)
{
	int fd = open(filename, flag, mode);

	return fd;
}

int rpc_read(int fdr, char *buff, int count)
{
	int rdval = read(fdr, buff, count);

	return rdval;
}

int rpc_write(int fdw, char *buff, int count)
{
	int wrval = read(fdw, buff, count);

	return wrval;
}

int rpc_close(int fd)
{
	int retval = close(fd);

	return retval;
}

int rpc_lseek(int fd, int offset, int whence)
{
	int offstval = lseek(fd, offset, whence);

	return offstval;
}
