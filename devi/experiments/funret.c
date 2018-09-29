#include <stdio.h>
int* fun()
{
	int e = 10;
	printf("e is %u e is %d\n",&e,e);
	return &e;
}
int fun1()
{
	int c = 20;
	printf("c is %u c is %d\n",&c,c);
	return c;
}
main()
{
	int b = 20;
	int d;
	d = fun1();
	printf("d = %d\n", d);
	printf("d = %u\n", &d);
	int *p;
	p = fun();
	printf("%u\n",p);
	printf("%u\n",*p);
}
