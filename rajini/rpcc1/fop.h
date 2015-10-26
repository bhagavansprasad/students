int aopen(char *fname, int mode, int flags);
int aread(int rfd, char *buff, int len);
int awrite(int wfd, char *buff, int len);
off_t alseek(int rfd, off_t offset, int whence);
int aclose(int fd);

