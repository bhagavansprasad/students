int rpcc_open( char *fn, int flags, int mode);
int rpcc_read( int rfd, char *buff, int len);
int rpcc_write( int wfd, char *buff, int rretval);
int rpcc_alseek(int rfd, off_t l, int pos);
int rpcc_close(int wfd);

