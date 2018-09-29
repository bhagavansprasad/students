#include<stdio.h>
#include<stdlib.h>
main()
{
	int pid,p[2];
	int retval;
	char *buff="hello";
	char *inbuff[5];
	pipe(p);
	pid=fork();
	if(pid==0)
	{
		printf("child existing\n");
	}
	else
	{
	close(p[1]);
	
		retval=read(p[0],inbuff,5);
		printf("value returend :%d\n",retval);
	}
}
