#include<stdio.h>

extern int a;

int new_fun()
{

	printf("-->a:%d\n",a);

	a++;

	printf("-->a:%d\n",a);

}	
