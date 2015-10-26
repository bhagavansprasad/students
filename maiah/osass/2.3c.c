#include "stdio.h"
static int k=32;
extern int i;
extern int j;
extern int l;
fun3()
{
	printf("i am function 3 in file 3\n");
	printf("%d\n",i);
	printf("%d\n",j);
	printf("%d\n",k);
	printf("%d\n",l);
}
