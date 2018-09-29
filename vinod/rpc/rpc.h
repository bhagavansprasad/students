int rpc_open(char *filename, int flag, int mode);
int rpc_read(int fdr, char *buff, int count);
int rpc_write(int fdw, char *buff, int count);
int rpc_close(int fd);
int rpc_lseek(int fd, int offset, int whence);
