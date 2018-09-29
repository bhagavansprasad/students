/* storing the data and send data */
struct s_open
{
	int fd;
	int errno;
};
struct s_read
{
	int fd;
	char buff[100];
	int errno;
};

struct s_write
{
	int fd;
	int errno;
};

struct s_close
{
	int fd;
};

union s_fun
{
	struct s_open open;
	struct s_read read;
	struct s_write write;
	struct s_close close;
};
struct school
{
	union s_fun fun;
};


