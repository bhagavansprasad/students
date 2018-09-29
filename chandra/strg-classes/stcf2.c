#include<stdio.h>
static int a=30;
void fun2(void)
{
	printf("a is : %d\n", a);
	a++;
	printf("a is : %d\n", a);
}

