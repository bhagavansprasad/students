int crpc_open(char *fname, int mode, int flags);
int crpc_read(int fd1, char *buff,int size );
int crpc_write(int fd2, char *buff,int size );
int  crpc_lseek(int fd, off_t offset, int whence);
int crpc_close(int fd);
