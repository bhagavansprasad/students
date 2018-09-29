#include <stdio.h>
int a = 10;
main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
		printf("child: a = %d\n",a);
	}
	else
	{
		a++;
		printf("parent: a = %d\n",a);
	}
}
