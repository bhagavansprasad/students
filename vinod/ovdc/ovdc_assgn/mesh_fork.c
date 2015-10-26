#include <stdio.h>
main()
{
	if(fork()==0)
		sleep(5);
	else if(fork()==0)
		sleep(5);
	else if(fork()==0)
		sleep(5);
	printf("Child pid -> %d Parent pid -> %d\n", getpid(), getppid());
	sleep(5);
}
