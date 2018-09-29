#include <stdio.h>
int c = 10;

main()
{
	int pid = fork();
	if(pid == 0)
	{
		printf("--> c vaule in child is :%d\n", c);
		printf("--> c address in child is :%p\n", &c);
		printf("pid: %d\n", getpid());
		printf("--> ppid: %d\n", getppid());
	}
	else
	{
		c++;
		printf("--> c vaule in parent is :%d\n", c);
		printf("--> c address in parent is :%p\n", &c);
		printf("pid: %d\n", getpid());
		printf("--> ppid: %d\n", getppid());
	}
}
