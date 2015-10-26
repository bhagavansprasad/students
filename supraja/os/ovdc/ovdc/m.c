#include <stdio.h>

main()
{
	
	int p[2],pid;
	pipe(p);
	
	pid = fork();
	if (pid == 0)
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
