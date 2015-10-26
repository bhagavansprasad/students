#include <stdio.h>
main()
{
	int i=0,pid;
	printf("ready to fork\n");
	pid=fork();
	if(pid==0)
	{
		printf("child starts\n");
		for(i=0;i<500;i++)
		printf("%d\t",i);
	}
	else
	{
		wait(0);
		printf("parent process\n");
	}
}
