#include <stdio.h>
main()
{
	int pid,p[2];
	int retval;
	char *buff="hello";
	char inbuff[5];
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		close(p[1]);
		sleep(5);
		printf("chile exiting\n");
	}
	else
	{
		close(p[1]);
		retval = read(p[0],inbuff,5);
		printf("vlaue returned : %d\n",retval);
	}
}
