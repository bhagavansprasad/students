#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void abc();
main()
{
	int fd;
	signal(SIGSYS,abc);
	fd=open("t.c",O_RDONLY);
	lseek(fd,01,5);
}
void abc()
{
	printf("illegal use of system call\n");
	exit(0);
}
