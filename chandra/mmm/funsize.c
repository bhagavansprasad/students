#include <stdio.h>
main()
{
	int a = 10, b = 20;
	printf("bmain %u\n", &b);
	printf("amain %u\n", &a);
	printf("\n");
	fun(a, b);
}
int fun(int x, int y)
{
	int c = 30, d = 40, g, h;
	printf("yfun %u\n", &y);
	printf("xfun %u\n", &x);
	printf("hfun %u\n", &h);
	printf("gfun %u\n", &g);
	printf("dfun %u\n", &d);
	printf("cfun %u\n", &c);
	printf("\n");
	fun1(c, d);
}
int fun1(int s, int t)
{
	int e = 50, f = 60, i = 3, j = 4;
	printf("tfun1 %u\n", &t);
	printf("sfun1 %u\n", &s);
	printf("jfun1 %u\n", &j);
	printf("ifun1 %u\n", &i);
	printf("ffun1 %u\n", &f);
	printf("efun1 %u\n", &e);
}
