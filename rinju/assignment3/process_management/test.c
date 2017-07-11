
#include <stdio.h>
main()

{
	int pid;
	pid=fork();
	if(pid == 0)
	{
		while(1)
		{
			printf("i am child\n");
			printf("my pid = %d\n",getpid());
		}
	}
	else
	{
		while(1)
		{
			printf("i am parent\n");
			printf("my pid = %d\n",getpid());
		}
	}
}
