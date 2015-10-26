#include "stdio.h"
static int l=23;
extern int i;
extern int j;
extern int k;
fun2()
{
	printf("i am function 4 in file 4\n");
	printf("%d\n",i);
	printf("%d\n",j);
	printf("%d\n",k);
	printf("%d\n",l);
}
