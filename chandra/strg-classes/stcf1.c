#include<stdio.h>
static int a=20;
void fun1(void)
{
	printf("a is : %d\n", a);
	a++;
	printf("a is : %d\n", a);
}

