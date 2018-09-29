#include <stdio.h>
main()
{
	int p[2],pid;
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		printf("child pid --->%d\n",pid);
		printf("in child p[0] is %d p[1] is %d\n",p[0],p[1]);
	}
	else
	{
		sleep(3);
		printf("parent pid --->%d\n",pid);
		printf("in parent p[0] is %d p[1] is %d\n",p[0],p[1]);
	}
	exit(0);
}
