#include "stdio.h"
main()
{
	int i=0,pid;
	printf("read the fork \n");
	pid=fork();

	if(pid==0)
	{
		printf("child stats");
		for( i = 0 ; i < 500 ; i++ )
		{
			printf("i-->%d\n",i);

			printf("child ends");
		}
	}
	else
	{
		wait(0);
		printf("parent process");
	}
}
