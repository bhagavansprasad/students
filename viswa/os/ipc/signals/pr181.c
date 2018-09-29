#include <stdio.h>
#include <fcntl.h>
#include <signal.h>

void abc();
main()
{
	int fd;
	signal(SIGSYS,abc);
	fd = open( "t.txt", O_RDONLY);
	lseek(fd , 01,5);
}
void abc()
{
	printf("illegal use of system call\n");
	exit(0);
}
