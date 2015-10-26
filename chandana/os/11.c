#include<stdio.h>
main()
{
	int pid;
	pid=fork();
	if(pid>0)
		printf("parent process pid is%d\n",pid);
}
