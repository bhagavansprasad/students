#include<stdio.h>
main ()
{
	int a = 10,b = 20;
	fun(&a,&b);
	printf("%d,%d",a,b);
}
void fun(int *pa,int *pb)
{
	*pa = 15;
	*pb = 25;
}
