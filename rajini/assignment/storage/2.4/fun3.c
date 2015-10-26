#include "stdio.h"

//static int c=12;
int c=12;
extern int a;
extern int b;
extern int d;

fun3()
{
	printf("iam function3 in file 3\n");
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	printf("c=%d\n",c);
	printf("d=%d\n",d);

}
