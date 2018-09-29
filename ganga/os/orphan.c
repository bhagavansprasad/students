#include <stdio.h>

main()
{
	int pid = fork();
	if (pid == 0)
	{
		printf("child pid-->:%d\n", getpid());
		printf("child ppid-->:%d\n", getppid());
		sleep(2);
		printf("child pid-->:%d\n", getpid());
	}
	else
	{
		printf("parent pid-->:%d\n", getpid());
		printf("parent ppid-->:%d\n", getppid());
		printf("parent terminates\n");
	}
}
