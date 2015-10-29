#include<stdio.h>
#include "assheaderfile.h"
void fun2(int s, double j)
{
	char ch='A';
	double f=456.00;
	printf("I am function2\n");
	printf("the values from fun1 int s=%d and double j=%lf\n",s,j);
//	printf("from fun1 the addr of s is %u and j is %u\n",&s,&j);
	printf(" the addr of ch is %u and f is %u\n",&ch,&f);
	fun3(ch,f);
}
