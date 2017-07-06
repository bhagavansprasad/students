#include<stdio.h>
main()
{
	int i,x=1,y=1,fact,n=3,sum=0;
	for(i=0;i<=n;i++)
	{
		x=x*(x+i);
		y=y*(y+i);
		fact=x/y;
		sum=sum+fact;
	}
	printf("sum=%d",sum);
}

