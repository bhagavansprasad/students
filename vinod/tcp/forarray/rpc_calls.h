void rpc_open(char *filename, int flag, int mode);
void rpc_read(int fdr, char *buff, int count);
void rpc_write(int fdw, char *buff, int count);
void rpc_close(int fd);
void rpc_lseek(int fd, int offset, int whence);
void get_first();
void get_next(char ch);
void get_prev(char ch);
void get_last();
