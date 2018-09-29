#include<stdio.h>
main()
{
	int a=10;
	int *p=&a;
	int **pp=&p;
	int ***ppp=&pp;
	//printf("%d %u %u %u\n", a, p, pp, ppp);
	printf("%d %u %u %u\n", a, *p, **pp, ***ppp);

}
