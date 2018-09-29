#include <stdio.h>

main()
{
	int pid,p[2];
	int retval;
	char buff[10];

	pipe(p);
	pid = fork();

	if(pid == 0)
		printf("child exiting \n");
	else
	{	
		close(p[0]);
		retval  = write(p[1] , buff , 1);
		printf("retval =%d\n",retval);
		printf("parent is exiting \n");
	}
}
