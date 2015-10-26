#include <stdio.h>
#include "fcntl.h"
#include "sys/types.h" 
#include "sys/stat.h"
#include <stdlib.h>

main(int argc, char *argv[])
{
	char buff[512];
	int fd1, fd2, rv, len = 10;

	if (argc < 3)
	{
		printf("Invalid or insufficient arguments\n");
		printf("Usage: acp <src file> <destination file>\n\n");
		exit(1);
	}

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_CREAT | O_RDWR, 0664);

	while(1)
	{
		rv = read(fd1, buff, len);
		buff[rv] = '\0';
		write(fd2, buff, rv);

		if(rv < len)
			break;
	}
	close(fd1);
	close(fd2);
}

