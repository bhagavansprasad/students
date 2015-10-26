struct open
{
	const char *pathname[500];
	int flags;
	mode_t mode;
}sopen;


struct read
{
	int fd;
	void *buf[100];
	size_t count;
}sread;

/*struct write
{
	int fd;
	void *buf[100];
	int count;
}swrite;*/
