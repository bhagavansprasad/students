#include<stdio.h>
int add_fun(int a,int b)
{
	int c;
	return c = a + b;
	
}
int mul_fun(int a,int b)
{
	int c;
	return c = a * b;
}
int div_fun(int a,int b)
{
	int c;
	return c = a/b;
}
int sub_fun(int a,int b)
{
	int c;
	return c = a - b;
}
int main()
{
	int retval=0;
	int (*fptr)(int ,int );
	
	fptr = &add_fun;
	retval = fptr(2,4);
	printf("add : %d\n",retval);

	fptr = &mul_fun;
	retval = fptr(3,4);
	printf("mul : %d\n",retval);

	fptr = &div_func;
	retval = fptr(4,2);
	printf("div : %d\n",retval);

	fptr = &sub_func;
	retval = fptr(10,2);
	printf("sub : %d\n",retval);

}	
