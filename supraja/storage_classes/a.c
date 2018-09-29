/*#include<stdio.h>
//static int a=10;
void my_function(void)
{
printf("%d\n",a);
}
int main()
{
static int a=10;
//int b;
printf("%d\n",a);
//printf("%d\n",b);
my_function();
}*/
#include<stdio.h>
#include"defs.h"
int a = 10;
int b=20;
main()
{
	printf("-->MAX :%d\r\n", MAX);
	printf("-->a :%d\r\n", a);
	printf("-->b :%d\r\n",b);

	my_function1();
	my_function2();
}

