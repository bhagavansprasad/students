#include <stdio.h>
main()
{
	printf("after the exec my process id is %d\n",getpid());
	printf("my parent process id is %d\n",getppid());

	printf("exec ends\n");
}
