#include <stdio.h>
//int a=10;
main()
{
	int a=10,pid;
	printf("--->the address of a before fork is %p\n",&a);
	a++;
	printf("--->the address of a before fork is %p\n",&a);
	pid=fork();
	if(pid==0)
	{
		printf("--->the address of a after fork is %p\n",&a);
		a++;
		printf("--->the address of a after fork is %p\n",&a);

	}
}
