#include <stdio.h>
main()
{
	int p[2] ,retval , pid;
	retval = pipe(p);
	pid = fork();
	if(pid == 0)
	{
		ovd(p[0]);
	}
	else
	{
		ovc(p[1]);
	}
}
