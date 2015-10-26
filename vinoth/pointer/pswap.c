#include<stdio.h>
main()
{
	int a=10, b=20;
	printf("%d,%d\n",a,b);
	swapbyvalue(a,b);
	printf("%d,%d\n",a,b);
	swapbyreference(&a,&b);
	printf("%d,%d\n",a,b);
	swapbyreferencetwo(&a,&b);
	printf("%d,%d\n",a,b);
}

int swapbyvalue(int x, int y)
{
	int t;
	t=x;
	x=y;
	y=t;
}

int swapbyreference(int *p, int *q)
{
	int t;
	t=*p;
	*p=q;
	*q=t;
}

int swapbyreferencetwo(int *m, int *n)
{
	int t;
	t=m;
	m=n;
	n=t;
}




