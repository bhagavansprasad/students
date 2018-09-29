int aopen(char *fname, int mode, int flags);
int aread(int fd1, char *buff,int size );
int awrite(int fd2, char *buff,int size );
int  alseek(int fd, off_t offset, int whence);
int aclose (int fd);
