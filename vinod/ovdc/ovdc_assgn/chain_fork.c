#include <stdio.h>
main()
{
	if(fork()==0)
	{
		if(fork()==0)
			if(fork()==0);
	}
	printf("Child pid -> %d Parent pid -> %d\n", getpid(), getppid());
	sleep(5);
}
