#include<stdio.h>
struct node
{
	int pid;
	int giffies;
}s,rc;
int ovd(int p);
int ovc(int p);
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
		printf("%d\n",pid);
		ovc(p[0]);
	}
}
