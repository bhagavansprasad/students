#include <stdio.h>
void my_fun1(void)
{
	
	static int a = 20;
	printf("----->a :%d\r\n", a);
	a++;
	printf("----->a :%d\r\n", a);
}
