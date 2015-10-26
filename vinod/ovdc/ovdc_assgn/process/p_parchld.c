#include <stdio.h>
main()
{
	if(fork()==0)
	{
	sleep(1);
	printf("LIST OF ALL Child IDS\n");
	printf("process id ---------> %u\n", getpid());
	printf("parent process id --> %u\n", getppid());
	printf("user id ------------> %u\n", getuid());
	printf("effective user id --> %u\n", geteuid());
	printf("group id -----------> %u\n", getgid());
	printf("effective group id -> %u\n", getegid());
	}
	else
	{
	printf("LIST OF ALL Parent IDS\n");
	printf("process id ---------> %u\n", getpid());
	printf("parent process id --> %u\n", getppid());
	printf("user id ------------> %u\n", getuid());
	printf("effective user id --> %u\n", geteuid());
	printf("group id -----------> %u\n", getgid());
	printf("effective group id -> %u\n", getegid());
	}
	sleep(20);
}
