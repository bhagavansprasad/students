
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "signal.h"
#define MAX 16

void abc();
main()
{
	char *msg1="hello world ";
	char inbuff[MAX];
	int p[2],i,pid;
	int retval;
	
	pipe(p);
	signal(SIGPIPE,abc);
	pid=fork();
	
	if(pid==0)	
	{	
		//close(p[1]);
		//sleep(5);
		printf("\ni am child exit\n");
	}
	else	
	{
		printf("\n i am parent\n");
		
		close(p[0]);
		///retval=read(p[0],inbuff,MAX);
		retval=write(p[1],msg1,MAX);
	
		printf("\n retval --> %d\n",retval);
		printf("\n parentexit\n");
	}

}


void abc()
{
	printf("parent failed");
}

