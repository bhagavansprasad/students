#include<stdio.h>
main()
{
	int i,n=3,c=1,sum=0;
	for(i=0;i<n; )
	{
		i=i+1;
		c=c*i;
		sum=sum+c;
	}
	printf("%d",sum);
}
