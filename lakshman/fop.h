int aopen(const char *pathname, int flags, mode_t mode);
int aclose(int fd);
size_t aread(int fd, void *buf, size_t count);
int awrite(int q,char *buff,int r);
