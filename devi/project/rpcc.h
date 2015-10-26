
ssize_t write(int fd, const void *buf, size_t count);
off_t lseek(int fd, off_t offset, int whence);
ssize_t read(int fd, void *buf, size_t count);
extern int open (const char *__file, int __oflag, ...) __nonnull ((1));
int close(int fd);
