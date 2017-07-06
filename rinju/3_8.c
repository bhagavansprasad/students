#include<stdio.h>
main()
{
	int fact,i,n=5,j,fact1=1,fact2=1,sum=0;
	for(i=1;i<=n;i++)
	{
		fact1=fact1*i;
		fact2=fact2*(i+1);
		fact=fact2/fact1;
		sum=sum+fact;
	}
	printf("sum=%d",sum);
}
