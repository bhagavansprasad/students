struct open
{
	char p[10];
	int m;
	int f;
};

struct read
{
	int m;
	char b[100];
	int f;
};

struct write
{
	int m;
	char b[100];
	int f;
};

struct lseek
{
	int m;
	off_t p;
	int qr;
};

struct close
{
	int m;
};

union tag
{

	struct open ope;
	struct read rd;
	struct write wtr;
	struct lseek lsk;
	struct close cls;
};
struct ch
{
	union tag t;
	int i;
};
