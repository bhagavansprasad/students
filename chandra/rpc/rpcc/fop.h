int aopen(char *rfd, int flags, int mode);
int aread(int rfd, char *buff, int len);
int awrite(int wfd, char *buff, int rretval);
int alseek(int rfd,  off_t l, int pos);
int aclose(int wfd);

