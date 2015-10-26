#include <stdio.h>

main()
{
	extern **environ;
	int pid , i;

	pid = fork();

	if(pid == 0)
	{
		printf("\n in child environmental block is at %u \n",environ);
		for( i = 0 ; environ[i] ; i++)
			printf("environ[%d]->%s\n",i,environ[i]);
	}
	else
	{
		wait(0);
		printf("\n in parent environmental block is at %u\n",*environ);
		for( i =0 ; environ[i] ; i++)
			printf("environ[%d] -> %s \n",i, environ[i]);
	}
}
