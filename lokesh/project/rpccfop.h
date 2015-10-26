int rpccopen(char *fname,int mode,int flags);
int rpccread(int rfd,char *buff ,int len);
int rpccwrite(int wfd, char *buff,int len);
off_t rpcclseek(int rfd,off_t offset, int whence);
int rpccclose(int fd);

struct open_data
{
char fname[128];
int mode;
int flags;
};

struct read_data
{
int rfd;
char rbuff[256];
int len;
};

struct write_data
{
int len;
};

struct lseek_data
{
int rfd;
off_t offset;
int whence;
};

struct close_data
{
int fd;
};
union tag
{
struct open_data os;
struct read_data rs;
struct write_data ws;
struct lseek_data ls;
struct close_data cs;
};

struct loke
{
union tag uni;
int fope;
};

