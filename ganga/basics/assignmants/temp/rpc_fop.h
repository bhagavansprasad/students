int rpc_open(char *fname, int mode, int flags);

int rpc_read(int fd1, char *buff, int size);

int rpc_write(int fd2, char *buff, int size);

int rpc_lseek(int fd1, int new_offset, int whence);

int rpc_close(int fd);

int rpc_foperations()
{
	struct open_data
	{
		char *fname;

		int mode;

		int flags;
	};

	struct read_data
	{

		int fd1;

		char buff;

		int size;
	};

	struct write_data
	{

		int fd2;

		char buff;

		int size;
	};

	struct lseek_data
	{

		int fd1;

		int new_offset;

		int whence;
	};

	struct close_data
	{
		int	close(fd);
	};
};
