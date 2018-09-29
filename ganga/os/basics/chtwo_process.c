#include <stdio.h>
int c = 10;

main()
{
	int pid = fork();
	if(pid == 0)
	{
		while(1)
		{
			c++;
			printf("--> c vaule in child is :%d\n", c);
			printf("--> c address in child is :%p\n", &c);
			printf("pid: %d\n", getpid());
			printf("--> ppid: %d\n", getppid());
			sleep(2);
		}
	}
	else
	{
		while(1)
		{
			printf("--> c vaule in parent is :%d\n", c);
			printf("--> c address in parent is :%p\n", &c);
			printf("pid: %d\n", getpid());
			printf("--> ppid: %d\n", getppid());
			sleep(2);
		}
	}
}
