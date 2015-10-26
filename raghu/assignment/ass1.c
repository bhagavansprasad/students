#include <stdio.h>
main()
{
	int a =10;
	int  pid;
	pid = fork();
	if(pid == 0)
	{
		wait();
		printf("the child value is %d\n",a);
	}
	else
	{
		printf("the parent value is %d\n",a);
	}
}
