#include <stdio.h>
main()
{
	int pid,p[2];
	int retval;
	char *buff ="hello";
	char inbuff[5];
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		//close(p[0]);
		//retval = read(p[0],inbuff,5);
		//printf("the child value of the returned :%d\n",retval);
		printf("child existing \n");
	}
	else
	{
		close(p[1]);
		//write(p[1],buff,5);
		retval = read(p[0],inbuff,5);
		printf("--->%s\n",inbuff);
		printf("the parent value of the returned :%d\n",retval);
	}
}
