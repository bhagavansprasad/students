#include <stdio.h>
int a = 10;
main()
{
	int * p ;
	int pid;
	pid = fork();
	if(pid == 0)
	{
		printf("print the value of a in child %d\n", a);
		printf("print the address of a in child%u\n", &a);
		}
	else
	{
		printf("print the value of a in parent %d\n", a);
	     p = &a;
		 *p = 20;
		printf("print the value of a in parent after chnging %d\n", a);
		printf("print the address of a in parent %u\n", &a);
}

		printf("print the address of a in parent %d\n", a);
}
