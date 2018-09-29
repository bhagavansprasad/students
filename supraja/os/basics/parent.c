#include <stdio.h>
int parent()
{
int a=50;
//	extern int a;
	for( ; ; )
	{
		printf("parent pid : %d\n parent ppid : %d\n",getpid(),getppid());
		sleep(1);
		printf("parent a : %d\n",a);
	}
}
