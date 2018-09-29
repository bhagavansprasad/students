int aura_openc(char *fname, int flags);
int aura_readc(int fd, char *buf, int count);
int aura_writec(int fd, char *buf, int count);
int aura_lseekc(int fd, off_t offset, int whence);
int aura_closec(int fd);
