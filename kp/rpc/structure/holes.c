#include<stdio.h>
struct emp
{
	int d;
	char a;
	double b;
	char c;
	int e;
	char f;
}n;
main()
{
	struct emp;
	n.a='a';
	n.b=10;
	n.c='c';
	n.d=10;
	n.e=8;
	n.f='f';
	printf("%d\n",sizeof n);
	printf("%u\n%u\n%u\n%u\n%u\n%u\n",&n.d,&n.a,&n.b,&n.c,&n.e,&n.f);
}

