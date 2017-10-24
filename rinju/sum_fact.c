#include<stdio.h>
main()
{
	int fact=1,i,j,n=10,sum=0;
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
		sum=sum+fact;
		printf("%d ",fact);
	}
	printf("sum=%d",sum);
}
