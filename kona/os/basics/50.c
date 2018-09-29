#include <stdio.h>
main()
{
	printf("before exec my ID is :%d\n",getpid());
	printf("my parent ID is :%d\n",getppid());
	printf("exec starts\n");
	execl("/home/bhagavan/students/kona/os/basics/51","51",(char *)0);
	printf("this will not print\n");
}


