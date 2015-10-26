#include <stdio.h>
main()
{
	int a=12,b=98;
	fun(a,b);
}
int fun(int x,int y)
{
	fun2(x,y);
}

int fun2(int p,int q)
{
	char a[5]={1,2,3,4,5};
	int  b=10;
	short int c=12;
	int d[10]= {10};

	printf("adress of a ---> %u\n", (unsigned int) a);
	printf("adress of b ---> %u\n", (unsigned int) &b);
	printf("adress of c ---> %u\n", (unsigned int) &c);
	printf("adress of d ---> %u\n", (unsigned int) d);

	printf("%c\n%d\n", a[1], b);
}

