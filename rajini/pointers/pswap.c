#include "stdio.h"
main()
{
	int a=10,b=20;
	printf("%d",a);
	printf("%d",b);
	swap(a,b);
	printf("\n");
	printf("%d%d\n",a);		
	printf("%d%d\n",b);		
}
int swap(int x,int y)
{
int t;

printf("%d",x,y);
printf("\n");
	t=x;
	x=y;
	y=t;

	printf("x=%d\n",x);		
	printf("y=%d\n",y);		
}

