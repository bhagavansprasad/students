#include <stdio.h>
float z;
int* fun(int x, float y)
{
	z= x*y;
	printf("AAdr of z is %u and val is %f\n", &z, z);
	//k =(int*)&z;
	//return k;
	return &z;
}
//int* (*fptr)(int,float) = fun;
//int fun1((int*)(*fptr)(int,float));
int main()
{
	int x = 10, *s;
	float y = 20.00;
	int* (*fptr)(int,float) = fun;
	//s = fun1(fptr);
	//printf("
	s = fptr(x, y);
	printf("the addr of s is %u\n", s);
	//*s = fptr(x, y);
	printf("val at s is s =%f\n",*s);
	return 0;
}
