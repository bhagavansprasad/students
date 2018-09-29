#include <stdio.h>
#include <stdlib.h>

main()
{
	int prd,crd,pid;
	int p[2];
	
	pipe(p);

	pid = fork();

	if(pid == 0)
	{
		prd = ovd(p[1]);
	}

	else
	{
		wait(0);
		crd = ovc(p[0]);
	}

}
