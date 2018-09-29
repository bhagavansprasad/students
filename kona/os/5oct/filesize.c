#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
main(argc, argv)
	int argc;
	char *argv[];

{
	int             ret;
	struct stat     bur;

	if (argc == 1)
	{
		ret = stat(argv[0], &bur);
	}
	else
	{
		ret = stat(argv[1], &bur);
	}

	if (ret < 0)

	{
		printf("stat failed, errno = %d\n",errno);
		exit(0);
	}

	printf("File system block size is = %d\n",bur.st_blksize);
}
