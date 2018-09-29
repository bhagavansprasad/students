#include<stdio.h>
main()
{
	int i,pid,exitstat,status,j=0;
	pid=fork();
	if(pid==0)
	{
		i=10/j;
	}
	else
	{
		wait(&status);
		if((status&0X80))
			printf("our core dumped\n");
	}
}
