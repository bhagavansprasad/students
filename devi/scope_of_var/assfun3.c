#include <stdio.h>
#include "assheaderfile.h"
void fun3(char c,double g)
{	
	char str[100]="Aura";
	printf("I am function3\n");
	printf("the values from fun2 c=%c\tg=%lf\n",c,g);
//	printf("the addr of char c is %u and double d is %u\n",&c,&g);
	printf("from fun3 the val of str is %s and adr is %u",str,&str);
}
