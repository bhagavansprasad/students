	   ssize_t rpcc_write(int fd,const void *buf, size_t count);
       off_t rpcc_lseek(int fd, off_t offset, int whence);
       ssize_t rpcc_read(int fd, void *buf, size_t count);
		int rpcc_open (const char *pathname,int flags,mode_t mode);
       int rpcc_close(int fd);

