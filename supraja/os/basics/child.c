#include <stdio.h>
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
