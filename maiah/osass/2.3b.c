#include "stdio.h"
static int j=14;
extern int i;
extern int k;
extern int l;
fun4()
{
	
	printf("i am function 2 in file 2\n");
	printf("%d\n",i);
	printf("%d\n",j);
	printf("%d\n",k);
	printf("%d\n",l);
}

