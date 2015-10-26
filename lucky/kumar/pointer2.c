#include<stdio.h>
main()
{
   int a=10;
	int*p;
	p=&a;
	printf("%d\n",*p);
	*p=20;
	printf("%d\n",*p);
}
