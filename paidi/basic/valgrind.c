#include<stdio.h>
#include <stdlib.h>

main()
{
	fun();
	fun1();
}
fun()
{
	int *p= malloc(sizeof(100));
	printf("add____ %d\n",p);
        free(p);
}
fun1()
{
	char *a= malloc(sizeof(10));
	printf("add______%d\n",a);
}
