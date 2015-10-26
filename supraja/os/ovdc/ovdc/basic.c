#include <stdio.h>
main()
{
	printf("pid is : %d\n",getpid());
	for(;;)
	printf("pid is : %d\t",getpid());
}
