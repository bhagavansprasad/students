#include <stdio.h>
/*main()
{
	int i,pid,exitstat;
	short int status;
	pid=fork();
	if(pid==0)
	{
		printf("enter exit stat :");
		sleep(3);
		//scanf("%d",&i);
		exit(3);
	}
	else
	{
		wait(&status);
		if((status & 0xff)!=0)
		{
			printf("signal intrrupted\n");
		}
		else
		{
		   printf("----%d\n",status);
			exitstat=(int)status/256;
			printf("exit status from %d was %d\n",pid,exitstat);
			sleep(1);
		}
	}
}*/


main()
{
	int pid,exitstat;
	short int status;
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
			printf("signal intrrupted\n");
		}
		else
		{
		   //printf("----%d\n",status);
			exitstat=(int)status/256;
			printf("exit status from %d was %d\n",pid,exitstat);
			//sleep(1);
		}
	}
}
