#include <stdio.h>

main()
{
	printf("hi\n");
	printf("how\n");
	printf("hello\n");
	printf("after the exec my process id is %d\n",getpid());
	printf("my parent process id is %d\n",getpid());
}
