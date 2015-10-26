#include <stdio.h>
main()
{
	fun();
	fun();
	fun();
}
void fun(void)
{
	static  a=10;
	printf("%d\n",a);
	a++;
}
