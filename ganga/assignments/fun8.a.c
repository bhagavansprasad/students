#include<stdio.h>
extern int a;
#define MAX 5

void my_function1(void)
{
	printf("-->MAX :%d\r\n", MAX);
	printf("-->a :%d\r\n", a);
}
