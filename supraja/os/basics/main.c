#include <stdio.h>
int parent();
int child();
int a=10;
main()
{
printf("%d\n",a);
	int pid;
	pid=fork();
	if(fork>0)
	{
		child();
		printf("child\n");
	}
	else
	{
		parent();
		printf("parent\n");
		sleep(1);
	}
}
int child()
{
	extern int a;
	a=100;
	for( ; ; )
	{
		printf(" child pid : %d\n child ppid : %d\n",getpid(),getppid());
		sleep(1);
		printf("child a : %d\n",a);
	}
}

