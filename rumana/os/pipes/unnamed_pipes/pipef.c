#include<stdio.h>
main()
{
	int pid,p[2];
	pipe(p);
	pid=fork();
	if(pid==0)
	{
		printf("in child is p[0]is %d p[1] is %d\n",p[0],p[1]);
	}
	else
	{
		printf("in parent is p[0] is %d p[1] is %d\n ",p[0],p[1]);
	}
}

