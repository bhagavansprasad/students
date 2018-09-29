#include <stdio.h>
#include <signal.h>

void abc();

main()
{
	int pid,p[2];
	int retv;
	char buff[10];
	
	pipe(p);
	//signal(SIGPIPE , abc );
	pid = fork();

	if( pid == 0)
	{
		sleep(5);
		printf("child existing \n");
	}
	else
	{
		close(p[0]);
		retv = write(p[1] , buff , 1);
		printf("value returned :%d ->str:%s\n",retv,buff);
		printf("parent existing \n");
	}
}


void abc()
{
	printf("parent failed\n");
}
