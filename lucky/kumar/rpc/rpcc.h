
int rpcc_open(char *pathname, int mode, int flags);

int rpcc_read(int fd, char *buf, int count);

int rpcc_write(int fd, char *buf, int count);

int rpcc_lseek(int fd, off_t offset, int whence);

int rpcc_close(int fd);
