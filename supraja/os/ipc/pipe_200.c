#include <stdio.h>
int main()
{
	int pid,p[2];
	int retval;
	char *buff="hello";
	char inbuff[5];
	pipe(p);
	pid=fork();
	if(pid==0)
	{
		printf("child Exiting \n");
	}
	else
	{
		retval=read(p[0],inbuff,5);
		printf("Value returned :%d \n",retval);
	}
}
