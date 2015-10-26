#include<stdio.h>
#include<unistd.h>
main()
{
	int pid,p[2];
	pipe(p);
	pid=fork();
	if(pid==0)
	{
		close(p[0]);
		ovd(p[1]);
	}
	else
	{
		close(p[1]);
		ovc(p[0]);
	}
}
