#include <stdio.h>
int* fun(static int , static int );
main()
{
	int *p;
	p = fun(10, 20);
	printf("%d\n",p);
}

int* fun(static int i, static int j)
{
int *p, *q;
p = &i;
q = &j;
if(i>=40)
return p;
else 
return q;
}
