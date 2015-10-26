struct s_open
{
	int fd;
	int erno;
};

struct s_read
{
	int r;
	char buff[100];
	int erno;
};

struct s_write
{
	int w;
	char buff[100];
	int erno;
};

struct s_close
{
	int fd;
	int erno;
};

struct s_lseek
{
	int fd;
	int erno;
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


