#include<stdio.h>
int swap(int *x,int *y)
{
	//printf("%d %d",*x,*y);
	int t=*x;
	*x=*y;
	*y=t;
	//printf("\n%d %d\n",*x,*y);
}
