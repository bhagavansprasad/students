#include <stdio.h>
void fun(void* c, int* a)
{
	//	printf("the value of c is %f and a is %d\n", *c, *a);
	int temp;
	temp = *a;
	*a = *c;
	*c = temp;
}
main()
{
	int a = 10;
	float c = 20;
	void (*fptr)(void*,int*) = fun;
	printf("%d and %d in main",c,a);
	fptr(&c,&a);
	//printf("addr of a is %u and c is %u\n",&a,&c);
	printf("%d and %d in main",c,a);
}
