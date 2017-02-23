#include<stdio.h>
main()
{
	int i=1,j=1,n=5;
	int k=n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			printf("%d",j);
		}
		printf("\n\t");
		k--;
	}
}
