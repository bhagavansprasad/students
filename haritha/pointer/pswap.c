#include<stdio.h>
int t=0;
main()
{
	int a=30,b=20;
	printf("n-->%d%d",a,b);
	printf("\n");
	swap_by_value(a,b);
	printf("val-->%d%d",a,b);
	printf("\n");

	swap_by_reference1(&a,&b);
	printf("ref-->%d%d",a,b);
	printf("\n");
	swap_by_reference2(&a,&b);
	printf("ref2-->%d%d",a,b);
	printf("\n");

}
int swap_by_value(int x,int y)
{
	printf("y-->%d%d",x,y);
	printf("\n");

	t=x;
	x=y;
	y=t;
	printf("x-->%d%d",x,y);
	printf("\n");

}
int swap_by_reference1(int *p,int *q)
{
	printf("q-->%d%d",*p,*q);
	printf("\n");

	t=p;
	p=q;
	q=t;
	printf("p-->%d%d",*p,*q);
	printf("\n");

}
int swap_by_reference2(int *i,int *j)
{
	printf("i*-->%d%d",*i,*j);
	printf("\n");

	t=i;
	i=j;
	j=t;
	printf("i,j-->%d%d",*i,*j);
	printf("\n");
}

