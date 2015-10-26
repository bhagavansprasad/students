#include<stdio.h>
main()
{
int pid;
pid = fork();
if (pid == 0)
{
 	printf("i am the child,my process id is %d\n", getpid());
 	printf("the child's parent process id is %d\n", getppid());
	}
	else 
	{

 	printf("i am the preant,my process id is %d\n", getpid());
 	printf("the parents parent  process id is %d\n", getppid());
	}
}
