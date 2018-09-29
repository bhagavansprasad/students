#include <stdio.h>
main()
{
	printf("after the exec my process ID is %d\n ",getpid());
	printf("my parent process ID is %d\n",getppid());
	printf("exec ends\n");
}
