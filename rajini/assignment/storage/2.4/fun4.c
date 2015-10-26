#include "stdio.h"

//static int d=13;
int d=13;
extern int a;
extern int b;
extern int c;

fun4()
{
	printf("iam function 4 in file 4\n");
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	printf("c=%d\n",c);
	printf("d=%d\n",d);

}

