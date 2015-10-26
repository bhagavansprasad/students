#include<stdio.h>
static int a;
static int b;
static int c;

main()
{
	static int d=1;
	static int e=2;
	printf("d:%u\n", &d);
	printf("e:%u\n", &e);
	printf("a:%u\n", &a);
	printf("b:%u\n", &b);
	printf("c:%u\n", &c);
}
