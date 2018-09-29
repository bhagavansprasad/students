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

struct sadd
{
	int rval;
};

struct sfact
{
int fval;
};

struct saddafter
{
	int addval;

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
	struct sadd sa;
	struct sfact sf;
	struct saddafter saddval;
	struct sclose c;
};

struct server 
{
	int node;
	union time ts;
};
