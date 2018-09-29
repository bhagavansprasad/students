#include <stdio.h>
#include <fcntl.h>
struct student
{
	int pid;
	int giffies;
}s,rc;
main()
{
	int p[2],pid;
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
