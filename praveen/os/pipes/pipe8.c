#include <stdio.h>
main()
{
	int pid, p[2];
	char *buff = "hello";
	int retval;
	char inbuff[5];
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		close(p[1]);
		sleep(5);
		printf("the child is exiting\n");
	}
	else
	{
		retval = read(p[0],inbuff,5);
		printf("the value returned :%d\n",retval);
	}
}
