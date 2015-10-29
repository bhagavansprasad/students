#include <stdio.h>
#include "assheaderfile.h"
void fun1(int a,int b);
main()
{
	int a=10,b=20;
	printf("I am main\n");
	printf("values in main a=%d and b=%d\n",a,b);
	printf("the addr of a is %p and b is %p\n",&a,&b);
	printf("after changing\n");
//	printf("print cmd\n");
	fun1(a,b);
}
