#include<stdio.h>
main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("i am the child ,my process id is%d\n,getpid");
		printf("the childs parent process id %d\n,getppid");
	}
	else
	{
		printf("i am the parent,my process id is%d\n",getpid());
	printf("the parent process id is%d\n",getppid());
}
}
