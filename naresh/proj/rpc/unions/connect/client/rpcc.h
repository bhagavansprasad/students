int rpccopen(char * fname,int mode,int flags);
int rpccread(int fd,char * buff,int len);
int rpccwrite(int fd1,char * buff,int r);
int rpcclseek(int fd,off_t,int num);
int rpccclose(int fd);
