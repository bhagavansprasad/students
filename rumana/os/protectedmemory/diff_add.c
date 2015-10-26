#include<stdio.h>
int a=10;
main()
{
	int pid;
	printf("address of a is %p\n",&a);
	pid=fork();
	if(pid==0)
	{
		printf("chaild is %p\n",&a);
		a=a+5;
		printf("a value is %d\n",a);
	}
	else
	{
		printf("parent is %p\n",&a);
		a=a+10;
		printf("a value in parent is %d\n",a);
	}
}
