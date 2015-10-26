#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int ovd(int p);
int ovd(int p);

main()
{
	int p[2];
	int pid;
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		ovd(p[1]);
		exit(0);
	}
	else
	{
		ovc(p[0]);
		exit(0);
	}
}
