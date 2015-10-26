struct aopen 
{
	char file[100];
	int mode;
	int flag;
};

struct awrite
{
	int fd;
	char buff[100];
	int len;
};

struct aread
{
	int fd;
	char buff[100];
	int len;
};

struct aclose
{
	int fd;
};

union final
{
	struct aopen ope;
	struct awrite wri;
	struct aread rea;
	struct aclose clo;
};

struct student
{
	int op;
	union final fin;
};
