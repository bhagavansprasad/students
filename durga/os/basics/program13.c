#include<stdio.h>
main()
{
	int pid;
	while(1)
	{
	pid = fork();
	if(pid<0)
	printf("fork failed\n");
	else 
	printf("fork sucess");
	}

}
