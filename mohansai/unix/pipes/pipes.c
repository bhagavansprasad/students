#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#define MAX 16
main()
{
	char *msg1="hello world ";
	char inbuff[MAX];
	
	int p[2],i,pid;
	pipe(p);
	
	pid=fork();
	if(pid>0)	
	{	
		printf("\ni am parent");
		
		close(p[0]);
		write(p[1],msg1,MAX);

	}
	else	
	{
		printf("\n i am child\n");
		close(p[1]);
		sleep(1);
		
		read(p[0],inbuff,MAX);
		printf("\n%s\n",inbuff);
	}
	exit(0);
}








