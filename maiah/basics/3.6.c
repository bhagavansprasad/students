#include<stdio.h>
main()
{
	int i,n,f=1,sum=0;
	for(n=1;n<=5;n++)
	{
		for(i=n;i>=1;i--)
		{
			f=f*i;
			break;
		}
		sum=sum+f;
	}
	printf("%d",sum);
}
