#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,fd1;
	fd = open("t1.txt",O_RDONLY,0);
	printf("%d\n",fd);
	close(0);
	fd1 = open("t1.txt",O_RDONLY,0);
	printf("%d\n",fd1);
	
}
