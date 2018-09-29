int aopen(char *fname, int mode, int flags);
int aread(int rfd, char *buff, int len);
int awrite(int wfd, char *buff, int len);
int alseek(int rfd, int offset, int whence);
int aclose(int fd);

