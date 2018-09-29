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
	int c=0;
	printf("iam child\n");
	for(c=0; ;c++)
	{
		printf("child:%d\n",c);
	    sleep(10);
	}
}
parent()
{
	int p;
	printf("iam parent\n");
	for(p=0; ;p++)
	{
		printf("parent:%d\n",p);
	    sleep(10);
	}
}
