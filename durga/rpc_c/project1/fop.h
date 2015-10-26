int aopen(char *pathname, int mode, int falg);
int aread(int fd, char *buf, int len);
int awrite( int fd, char *buf, int len);
int alseek( int fd, int offset, int whence);
int aclose( int fd);

