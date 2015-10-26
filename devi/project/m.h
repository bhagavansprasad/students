       ssize_t aread(int fd, void *buf, size_t count);
       off_t alseek(int fd, off_t offset, int whence);
       ssize_t awrite(int fd, const void *buf, size_t count);
       int aclose(int fd);
       int aopen(const char *pathname, int flags, mode_t mode);
