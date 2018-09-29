#include "stdio.h"
main()
{
	int pid=getpid();
	printf("process id is %d\n ",getpid());
	while(1);
	{
		printf("process id %d\n ",pid);
	}
}
