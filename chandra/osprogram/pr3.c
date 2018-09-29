#include <stdio.h>
#include <fcntl.h>
main()
{
	int a=5, pid;
	pid = fork();
	if(pid > 0)
	{
	a++;
	printf("a is : %d\n", a);
	}
	if(pid == 0)
	{
	a++;
	printf("a is : %d\n", a);
	}

}
