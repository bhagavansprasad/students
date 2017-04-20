#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
main()
{
	int fd1, fd2, fd3;

	fd1 = open("a.txt", O_RDWR);
	fd2 = open("b.txt", O_RDWR);
	fd3 = open("c.txt", O_RDWR);

	printf("-->fd1 :%d, fd2 :%d, fd3 :%d\n", fd1, fd2, fd3);
	sleep(1);
}

