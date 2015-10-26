#include <stdio.h>
#include "fcntl.h"
#include "sys/types.h" 
#include "sys/stat.h"
#include <stdlib.h>

main()
{
	char buff[500];
	int fd1, fd2, rv, len = 10;
	fd1 = open("a.txt", O_RDONLY);
	fd2 = open("h.txt", O_CREAT | O_RDWR, 0664);

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

