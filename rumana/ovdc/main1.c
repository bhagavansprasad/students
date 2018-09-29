#include<stdio.h>
#include<fcntl.h>
struct node
{
	int pid;
	int giffies;
}s,rc;
main()
{
	int pid,p[2];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
	printf("%d\n",pid);
		ovd(p[1]);
	}
	else
	{
		ovc(p[0]);
	}
}
