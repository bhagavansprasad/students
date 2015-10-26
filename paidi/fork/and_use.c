#include <stdio.h>
main()
{
	int pid,exitstat,status;
	pid=fork();
	if(pid==0)
	{
		sleep(10);
		exit(3);
	}
	else
	{
		wait(&status);
		if((status & 0xff)!=0)
		{
			printf("signal interrupted\n");
		}
		else
		{
			exitstat=(int)status/256;
			printf("Exit status from %d was %d\n",pid,exitstat);
		}
	}

}
