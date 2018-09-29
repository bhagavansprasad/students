#include <stdio.h>
void fun1();
main()
{
	printf("address of main is :%u\n",main);
	printf("address of function fun1() is :%u\n",fun1);
}
void fun1()
{
	printf("sreenu kona\n");
}
