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

struct add
{
	int val1;
	int val2;
};

struct fact
{
	int val4;
};

struct addafter
{
	int val5;
};
struct close
{
	int m;
};

union tag
{
	struct open o;
	struct read r;
	struct write w;
	struct add a;
	struct fact f;
	struct addafter ad;
	struct close c;
};

struct ch
{
	union tag t;
	int flag;
};
