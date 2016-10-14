
#define CRPC_OPEN_REQ  1
#define CRPC_READ_REQ  2
#define CRPC_WRITE_REQ 3
#define CRPC_LSEEK_REQ 4
#define CRPC_CLOSE_REQ 5

int rpc_foperations(int operation, char *fname, int mode, int flags, int fd, char *buff, int size, int whence);
