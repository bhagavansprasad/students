#include <stdio.h>
#include <unistd.h>

main()
{
	printf("why\n");
	printf("when\n");
	printf("before exec my id is %d\n",getpid());
	execl("/home/bhagavan/students/raghu/ex2","ex2",(char *)0);
	printf("while\n");

}
