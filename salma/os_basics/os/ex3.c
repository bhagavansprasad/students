#include<stdio.h>
main()
{
	int a=10;
	int pid;
	printf("%p \n",&a);
	pid=fork();
	if(pid==0)
	{
		printf(" a address in child :%p \n",&a);
		sleep(1);
	}
	else
	{
		printf("a address in parent :%p \n",&a);
		sleep(1);
	}
}
