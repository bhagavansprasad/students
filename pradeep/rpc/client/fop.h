#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int aopen(char *pathname, int flags, int mode);
int aread(int fd,char *buff, int len);
int awrite(int fd,char *buff, int len);
int alseek(int fd, int offset, int whence);
int aclose(int fd);

int rpccopen(char *pathname, int flags, int mode);
int rpccread(int fd,char *buff, int len);
int rpccwrite(int fd,char *buff, int len);
int rpcclseek(int fd, int offset, int whence);
int rpccclose(int fd);
