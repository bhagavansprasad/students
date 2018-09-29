#include "stdio.h"
static int i=20;
extern int j;
extern int k;
extern int l;

fun1()
{
	printf("i am function 1 in file 1\n");
	printf("%d\n",i);
	printf("%d\n",j);
	printf("%d\n",k);
	printf("%d\n",l);
}
