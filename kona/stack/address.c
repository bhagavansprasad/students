#include <stdio.h>
void fun1(int ,int );
void fun2(int ,int );
void fun3(int ,int );
main()
{
	int a=10,b=20;
	printf("mainb       %u\n",&b);
	printf("maina       %u\n",&a);
	fun1(a,b);
}
void fun1(int c,int d)
{
	int e=10,f=20,x=30,y=40,z=50;
	printf("fun1z       %u\n",&z);
	printf("fun1y       %u\n",&y);
	printf("fun1x       %u\n",&x);
	printf("fun1f       %u\n",&f);
	printf("fun1e       %u\n",&e);
	printf("argvfun1c %u\n",&c);
	printf("argvfun1d %u\n",&d);
	fun2(e,f);
}
void fun2(int g,int h)
{
	int i=10,j=20;
	printf("fun2j       %u\n",&j);
	printf("fun2i       %u\n",&i);
	printf("argvfun2g %u\n",&g);
	printf("argvfun2h %u\n",&h);
	fun3(i,j);
}
void fun3(int k,int l)
{
	int m=10,n=20;
	printf("fun3n       %u\n",&n);
	printf("fun3m       %u\n",&m);
	printf("argvfun3k %u\n",&k);
	printf("argvfun3l %u\n",&l);
}
