#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
void abc();
main()
{
	int fd;
	signal(SIGSYS,abc);
	fd=open("t.c",O_RDONLY);
	lseek(fd,0l,5);
}
void abc()
{
	printf("illegal use of system call\n");
}
