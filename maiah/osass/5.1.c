#include "stdio.h"
int a=10;
main()
{
 	printf("----->a:%d\n",a);
 	my_function1();
	printf("----->a:%d\n",a);
 	my_function2();
 	printf("----->a:%d\n",a);
 	my_function1();
 	printf("----->a:%d\n",a);
 	new_function();
	printf("----->a:%d\n",a);
 	my_function2();
	printf("----->a:%d\n",a);
 	new_function();
	printf("----->a:%d\n",a);
 	a=my_function3();
	printf("----->a:%d\n",a);
}
void my_function1(void)
{
 	printf("---->a:%d\n",a);
	a++;
	printf("----->a:%d\n",a);
}
void my_function2(void)
{
	static int a=20;
 	printf("---->a:%d\n",a);
	a++;
	printf("----->a:%d\n",a);
}
void my_function3(void)
{
	int a=20;
 	printf("---->a:%d\n",a);
	a++;
	printf("----->a:%d\n",a);
	return a;
}
