#include<stdio.h>
//int a=10;
static int a=20;
void fun1(void)
{
	//static int a=20;
	printf("a is : %d\n", a);
	a++;
	printf("a is : %d\n", a);
}

//static int a=30;
void fun2(void)
{
	//static int a=30;
	printf("a is : %d\n", a);
	a++;
	printf("a is : %d\n", a);
}

main()
{
	printf("a is : %d\n", a);
	fun1();
	fun2();
	printf("a is : %d\n", a);
}

//static int a=20;

