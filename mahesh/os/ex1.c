#include <stdio.h>
main()
{
	printf("before exec my ID is %d\n",getpid());
	printf("my parent pid is %d\n", getppid());
	execl("/students/mahesh/os","ex2.out",(char *)0);
	printf("this will not print\n");
}
