int rpc_open(char *pathname, int mode, int flag);
int rpc_read(int fd, char *buf, int len);
int rpc_write(int fd, char *buf, int len);
int rpc_lseek( int fd, int offset, int whence);
int rpc_close(int fd);

