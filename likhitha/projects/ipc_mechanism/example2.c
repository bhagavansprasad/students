#include <stdio.h>
int a=10;
main()
{
	printf("I am forking a child process\n");
	int pid=fork();
	if(pid == 0)
	{
		printf("child process\n");
		printf("%d\n",getpid());
		printf("a is %d\n",a);
	}
	else
	{
		a++;
		printf("parent process\n");
		printf("%d\n",getppid());
		printf("a is %d\n",a);
	}
}
