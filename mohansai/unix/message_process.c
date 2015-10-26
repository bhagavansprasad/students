#include "stdio.h"
main()
{
	int pid,dip,cpid;
	pid=fork();
	if(pid==0)
	{
		printf("1 st child process id is %d \n",getpid());
		
		printf("first child  terminating from memory \n");
	}
	else
	{
		sleep(10);	
		dip=fork();
		
		if(dip==0)
		{
				
			printf("2 nd  child process id is %d \n",getpid());
		
			printf("second  child  terminating  \n");
		}
	else
		{
			cpid=wait(0);
			printf("child with pid %d died \n", cpid);
			
			cpid=wait(0);
			printf("child with pid %d died \n", cpid);
		}

	}

}


