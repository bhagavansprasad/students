#include<stdio.h>
main()
{
	int pid=0;
	pid=fork();
	if(pid==0)
	{
		child();
	}
	else
	{
		parent();
	}
}

child()
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("hello\n");
	}
}
parent()
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("how r u\n");
	}
}

