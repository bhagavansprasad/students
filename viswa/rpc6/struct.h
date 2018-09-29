struct aopen
{
	char file[100];
	int mode;
	int flag;
};

struct aread
{
	int fd;
	char buff[100];
	int len;

};

struct awrite
{
	int fd;
	char buff[100];
	int len;
};
struct aclose
{
	int fd;
};
union combine
{
	struct aopen open;
	struct aread read;
	struct awrite write;
	struct aclose close;
};

struct students
{
	int op;
	union combine comb;
};

/* storing the data and send data */
struct s_open
{
	int fd;
	int errno;
};
struct s_read
{
	int fd;
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


