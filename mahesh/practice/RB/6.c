#include <stdio.h>
fun()
{
	static int a=5;
	a++;
	printf("%d\n",a);
}
main()
{
	int a=20;
	fun();
	a++;
	fun();
	printf("%d\n",a);
}
