#include <stdio.h>
main()
{
	printf("after the exce my process is:%d\n",getpid());
	printf("my parent ID is:%d\n",getppid());
	printf("exec ends\n");

}
