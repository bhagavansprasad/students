#include <stdio.h>
main()
{
	int a =10;
	int pid;
	pid = fork();
	if (pid == 0)
	{
		printf("the child a value is %u\n",&a);
	}
	else 
	{
		printf("the parent a value is %u\n",&a);
	}
}
