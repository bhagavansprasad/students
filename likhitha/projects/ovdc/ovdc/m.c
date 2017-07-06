#include <stdio.h>

main()
{
	int p[2];
	int pid=fork() , retval ;
	retval = pipe(p);
	int wfd ,rfd;
	if(pid == 0)
	{
		ovd(wfd);
	}

	else
	{
		ovc(rfd);
	}

}

