struct open
{
char filename[20];
int mode;
int flag;
};

struct read
{
int fd;
char buff[100];
int len;
};

struct write
{
int fd;
char buff[100];
int len;
};

struct close
{
int fd;
}
union utag
{
struct open open;
struct read read;
struct write write;
struct close close;
};
struct data
{
int op;
union utag t;
};


