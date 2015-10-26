int rpccopen(char *fname,int mode,int flags);
int rpccread(int rfd,char *buff,int len);
int rpccwrite(int wfd,char *buff,int len);
int rpcclseek(int rfd,int offset,int whence);
int rpccclose(int fd);

