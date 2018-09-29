#include<stdio.h>
extern int c;
void my_fun1(void)
{

	printf("c:%d\n", c);
}


int a=10;
int b=12;
int c=13;
main()
{
	printf("a:%d\n", a);
	printf("b:%d\n", b);
	my_fun1();
}

