#include <stdio.h>
main()
{
	printf("LIST OF ALL IDS\n");
	printf("process id ---------> %u\n", getpid());
	printf("parent process id --> %u\n", getppid());
	printf("user id ------------> %u\n", getuid());
	printf("effective user id --> %u\n", geteuid());
	printf("group id -----------> %u\n", getgid());
	printf("effective group id -> %u\n", getegid());
}
