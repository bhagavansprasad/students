#include <stdio.h>
#include "assheaderfile.h"
void fun1(int a,int b)
{
	int e=50;
	float d=45.000000;
	printf("I am function1\n");
	printf("the values from main is x=%d and y=%d\n",a,b);
	//printf("the addr of x is %u and y is %u\n",&a,&b);
	printf("the addr of e is %u and d is %u\n",&e,&d);
	printf("after changing\n");
	fun2(e,d);
}
