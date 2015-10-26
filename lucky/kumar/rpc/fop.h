int aopen(char *pathname, int mode, int flags);

int aread(int fd, char *buf, int count);

int awrite(int fd, char *buf, int count);

int alseek(int fd, off_t offset, int whence);

int aclose(int fd);
