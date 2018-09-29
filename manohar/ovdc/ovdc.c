#include "define.h"
main()
{
	int pid,p[2],i;
	pipe(p);
	pid = fork();
	pid = fork();

	while(1)
	{
		printf("pid--->%d\n", getpid());
		for(i=0;;i++)
		{
		
		}
		sleep(1);
	}
}
