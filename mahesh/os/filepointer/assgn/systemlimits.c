#include <stdio.h>
main()
{
	printf("PID:%d\n",getpid());
	sleep(100);
	printf("PID:%d\n",getpid());
}
