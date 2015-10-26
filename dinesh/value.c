#include <stdio.h>
#include <fcntl.h>
main ()
{
	int a = 10,b = 20;
	fun(a,b);
	printf("%d ,%d",a,b);
}
void fun(int a,int b)
{
	a = 15;
	b = 25;
}

