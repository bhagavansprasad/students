#include "define.h"
int main()
{
	int pid, p[2];

	pipe(p);

	pid = fork();
	printf("-->fd :%d\n", pid);

	if(pid > 0)
	{	
		close(p[0]);
		ovd(p[1]);
		sleep(1);
	}
	else
	{
		close(p[1]);
		ovc(p[0]);
	}
	return 0;
}
