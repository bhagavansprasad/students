#include <stdio.h>
main()
{
	printf("Before exec my ID is %d\n",getpid());
	printf("My Parent process's ID is %d\n",getppid());

	printf("exec stats \n");
	execl("/home/bhagavan/students/rajini/OS/assign/execfn/ex2","b.out",(char *)0);
	printf("this will not print \n");
}
