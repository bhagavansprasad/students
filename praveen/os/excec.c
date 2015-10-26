#include <stdio.h>
main()
{
	printf("before exec my id is %d\n",getpid());
	printf("my parent process id is %d\n",getppid());


	printf("exec starts\n");
	execl("/home/bhagavan/students/praveen/os/ex2","ex2",(char *)0);
	printf("this will not print\n");
}
