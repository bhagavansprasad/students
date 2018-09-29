#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
main()
{
	int p[2],pid;
	pipe(p);
	pid = fork();
	if (pid == 0)
	{
		printf("--> in child <---\n");
		ovd_fun(p[1]);
		close(p[0]);
	}
	else
	{
		wait(0);
		printf("--> in parent <---\n");
		close(p[1]);
		ovc_fun(p[0]);
	}

}
