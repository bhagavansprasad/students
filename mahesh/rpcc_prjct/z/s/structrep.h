struct sopen
{
	int fd;
	int erno;
};

struct sread
{
	int rval;
	char buff[200];
	int erno;
};
struct swrite
{
	int rval;
	int erno;
};
struct sclose
{
	int rval;
	int erno;
};

union suns
{
	struct sopen o;
	struct sread r;
	struct swrite w;
	struct sclose c;
};

struct server
{
	int type;
	union suns a_uns;
};

