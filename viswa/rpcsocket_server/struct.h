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


