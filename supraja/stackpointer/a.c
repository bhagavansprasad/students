#include <stdio.h>
main()
{
	int a,b;
	printf("&a:%u\t &b:%u\n",&a,&b);
	fun1(a,b);
}
int fun1(int A,int B)
{
	int c,d;
	printf("&A:%u\t &B:%u\n",&A,&B);
	printf("&c:%u\t &d:%u\n",&c,&d);
	fun2(c,d);
}
int fun2(int C,int D)
{
	int e,f;
	printf("&C:%u\t &D:%u\n",&C,&D);
	printf("&e:%u\t &f:%u\n",&e,&f);
	fun3(e,f);
}
int fun3(int E,int F)
{
	int g,h;
	printf("&E:%u\t &F:%u\n",&E,&F);
	printf("&g:%u\t &h:%u\n",&g,&h);
}
