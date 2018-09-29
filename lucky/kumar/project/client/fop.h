#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int aopen(const char *pathname, int flags, mode_t mode);
ssize_t aread(int fd, void *buf, size_t count);
ssize_t awrite(int fd,void *buf, size_t count);
off_t alseek(int fd, off_t offset, int whence);
int aclose(int fd);

int rpccopen(const char *pathname, int flags, mode_t mode);
ssize_t rpccread(int fd,void *buf, size_t count);
ssize_t rpccwrite(int fd,void *buf, size_t count);
off_t rpcclseek(int fd, off_t offset, int whence);
int rpccclose(int fd);

