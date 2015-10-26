#include<stdio.h>
static int a=11;
static int b=12;
static int c=13;
main()
{
	//static int a=10;
	//static int b=10;
	//static int c=30;
	//static int a;
	//static int b;
	//static int c;
	printf("a:%u\n", &a);
	printf("b:%u\n", &b);
	printf("c:%u\n", &c);
}
