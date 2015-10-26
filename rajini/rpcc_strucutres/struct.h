int rpccopen(char * p,int mode,int flags);
int rpccread(int fd,char *buff,int len);
int rpccwrite(int fd,char *buff,int len);
off_t rpcclseek(int fd,off_t offset,int whence);
int rpccclose(int fd);


struct open_data
{
  char p[128];
  int mode;
  int flags;
  };

struct read_data
{
  int fd;
  char buff[256];
  int len;
  };

struct write_data
{
  int fd;
  char buff[256];
  int len;
  };

struct lseek_data
{
  int fd;
  int offset;
  int  whence;
  };
  
  struct close_data
{
  int fd;
  };
