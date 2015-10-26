#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
	int pid,p[2];
	char msg[100];
	pipe(p);
	pid = fork();
	if (pid == 0)
	{
		write
	}
}
