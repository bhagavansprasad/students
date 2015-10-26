#include<stdio.h>
	int fun1(int a,int b);
main()
{
	int a=10,b=20;
	printf("main address of a is %u\n",&a);
	printf("main address of b is %u\n",&b);
	fun1(a,b);
}
int fun1(int a,int b)
{
	int c=30,d=40,r=10;
	printf("fun1 a is %u\t fun1 b is %u\n fun1",&a,&b);
	printf("fun1 c is %u\t fun1 d is %u\n fun1",&c,&d);
	printf("unintvar is %u\n",&r);
	fun2(c,d);
}
int fun2(int c,  int d)
  {
  int e=50,f=60;
  printf("fun2 c is %u\t fun2 d is %u \n",&c,&d);
  printf("fun2 e is %u\t fun2 f is %u\n",&e,&f);
  }
