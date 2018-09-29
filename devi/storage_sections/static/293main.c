#include <stdio.h>
int a  = 10;
void my_fun1(void);
int main()
{
	printf("------>a :%d\r\n", a);
	my_fun1();
	printf("------>a :%d\r\n", a);
	my_fun1();
	printf("------>a :%d\r\n", a);
	return 0;
}
