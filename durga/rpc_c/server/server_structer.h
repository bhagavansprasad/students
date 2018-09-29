struct s_open
{
	int fd;
	int errno;
};

struct s_read
{
	int r;
	char buff[100];
	int errno;
};

struct s_write
{
	int w;
	char buff[100];
	int errno;
};

struct s_close
{
	int fd;
	int errno;
};

struct s_lseek
{
	int fd;
	int errno;
};

union tag
{
	struct s_open os;
	struct s_read rs;
	struct s_write ws;
	struct s_close cs;
	struct s_lseek ls;

};
struct server 
{
union tag u;
};


