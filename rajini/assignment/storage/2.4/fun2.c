#include "stdio.h"

//static int b=11;
int b=11;
extern int a;
extern int c;
extern int d;

fun2()
{
	printf("iam function 2 in the file 2\n");
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	printf("c=%d\n",c);
	printf("d=%d\n",d);

}
