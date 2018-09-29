#include <stdio.h>
main()
{
	int a=10;
	printf("\n In Main\n");
	printf("the val of a is %d and addr is %u\n",a,&a);
	fun1();
	fun2();
}
