int rpcc_open(char * fname,int flag,int mode);
int rpcc_read(int fd,char * buff,int len);
int rpcc_write(int fd1,char * buff,int r);
int rpcc_lseek(int fd,int k,int num);
int rpcc_close(int fd);
