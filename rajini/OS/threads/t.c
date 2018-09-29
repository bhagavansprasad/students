#include <stdio.h>
main()
{
	int i = 0;
	for(i = 0; i< 500; i++)
	{
		printf("%d. %d %d\n", i, getpid(), getppid());
		sleep(1);
	}
}

