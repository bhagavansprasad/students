#include "stdio.h"

//static int a=10;
int a=10;

extern int b;
extern int c;
extern int d;

fun1()
{
	printf("iam function1 in file 1\n");
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	printf("c=%d\n",c);
	printf("d=%d\n",d);
}


