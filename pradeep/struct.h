struct sopen
{
	const char *pathname[100];
	int flags;
	mode_t mode;
};

struct sread
{
	int fd;
	void *buf[100];
	size_t count;
};


struct swrite
{
	int fd;
	void *buf[100];
	size_t count;
};


struct slseek
{
	int fd;
	off_t offset;
	int whence;
};

struct sclose
{
	int fd;
};
