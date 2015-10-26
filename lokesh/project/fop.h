int aopen(char *fname, int flag, int mode);
int aread(int rfd, char*buff, int len);
int awrite(int wfd, char*buff, int len);
int alseek(int fd,int offset,int whence);
int aclose(int fd);
