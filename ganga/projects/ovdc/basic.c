#include <stdio.h>

main()
{
	printf("pid : %d\n", getpid());
	for( ; ;)
		printf("pid : %d\n", getpid());
}
