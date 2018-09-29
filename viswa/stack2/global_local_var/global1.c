#include <stdio.h>
void global_fun11();
void global_fun12();
int a=10;

void global_fun11(void)
{
	printf("-->a:%d\r\n",a);
	a++;
	printf("-->a:%d\r\n",a);
}
void global_fun12(void)
{
	int a=20;
	printf("-->a:%d\r\n",a);
	a++;
	printf("-->a:%d\r\n",a);
}
int global_fun13(void)
{
	int a=30;
	printf("-->a:%d\r\n",a);
	a++;
	printf("-->a:%d\r\n",a);
	return a;
}
/*
int global_new_fun1()
{
	return 0;
}

*/
main()
{
    int retval =0;
	printf("1-->a:%d\r\n",a);
	global_fun11();
	printf("2-->a:%d\n",a);
	global_fun11();
	printf("3-->a:%d\r\n",a);
	global_fun12();
	printf("4-->a:%d\r\n",a);
	global_fun12();
	printf("5-->a:%d\r\n",a);
	global_new_fun1();
	printf("5-->a:%d\r\n",a);
	global_new_fun1();
	printf("7-->a:%d\r\n",a);
	a = global_fun13();
	printf("8-->a :%d\r\n",a);
}

