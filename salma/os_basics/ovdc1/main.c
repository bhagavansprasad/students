#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
main()
{
	int pid = 0, p[2];

	pipe(p);

	pid = fork();
	if ( pid == 0)
	{
		close(p[0]);
		ovd(p[1]);
	}
	#if 0
	else
	{
		close(p[1]);
		ovc(p[0]);
	} 
	#endif
}
