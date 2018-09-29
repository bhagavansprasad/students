struct sopen
{
	int fd;
	int erno;
};

struct sread
{
	int retval;
	char buf[100];
	int erno;
};

struct swrite
{
	int retval;
	int erno;
};

struct sclose
{
	int retval;
	int erno;
};

union time
{
	struct sopen o;
	struct sread r;
	struct swrite w;
	struct sclose c;
};

struct server 
{
	int node;
	union time ts;
};
