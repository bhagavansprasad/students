#include <stdio.h>
main()
{
	int a=10,b=10;
	printf("&a:%u\t &b:%u\n",&a,&b);
	fun1(a,b);
}
int fun1(int A,int B)
{
	int c=10,d=10,m,n,o,p,s;
	printf("&A:%u\t &B:%u\n",&A,&B);
	printf("&c:%u\t &d:%u\n",&c,&d);
	printf("&m:%u\t &n:%u\n",&m,&n);
	printf("&o:%u\t &p:%u\n",&o,&p);
	printf("&s:%u\n",&s);
	fun2(c,d);
}
int fun2(int C,int D)
{
	int e=10,f=10;
	printf("&C:%u\t &D:%u\n",&C,&D);
	printf("&e:%u\t &f:%u\n",&e,&f);
	fun3(e,f);
}
int fun3(int E,int F)
{
	int g=10,h=10;
	printf("&E:%u\t &F:%u\n",&E,&F);
	printf("&g:%u\t &h:%u\n",&g,&h);
}
