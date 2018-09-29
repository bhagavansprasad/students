#include<stdio.h>
int fun1(int a,int b);
int fun2(int c,int d);
main()
{
	int a=10,b=20;
	printf("var a is %u\t var b is %u\n",&a,&b);
	fun1(a,b);
}
int fun1(int a,int b)
{
	int c=10,d=20,r;
	printf("arg a is %u\t arg b is %u\n",&a,&b);
	printf("var c is %u\t var d is %u\n",&c,&d);
	printf("unint var is %u\n",&r);
	fun2(c,d);
}
int fun2(int c,int d)
{
	int e=10,f=20;
	printf("arg c is %u\t arg d is %u\n",&c,&d);
	printf("var e is %u\t var f is %u\n",&e,&f);
}
