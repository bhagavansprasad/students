#include <stdio.h>
#include <signal.h>
main()
{

	int pid;

	pid=fork();

	if(pid==0)
	{

		printf(" child with  pid : %d \n", getpid());
	}  
 	else
	{ 
	    
 		printf("Parent with pid %d \n",getpid());
	}
}	

