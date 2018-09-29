#include <stdio.h>
main()
{
	long i;
	printf("process ID is %d\n",getpid());
	for(i=0;i<=4;i++)
		printf("i is %d\n",i);
}
