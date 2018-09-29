
#include<stdio.h>
main()
{
	int pid;
	pid=fork();
	if(pid<0)
		printf("fork failled\n");
	else
		printf("fork succeeded\n");
}
