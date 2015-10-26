#include <stdio.h>
#include <stdlib.h>
main()
{
	int pid,i=1;
	for(;;)
	{
		pid = fork();
		if(pid < 0)
		{
			printf("maximum concurrent process are %d\n",i);
		}
		if(pid == 0)
			i++;
		else
		{
			wait(0);
			exit(0);
		}
	}
}
