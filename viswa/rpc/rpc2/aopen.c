int aopen(char *file,int flag,int mode)
{
	int fd=open("file",flag,mode);
	return fd;
}

