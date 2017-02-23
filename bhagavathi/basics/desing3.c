#include<stdio.h>
main()
{
	int i=1,j=1,k,n=5,s=1,m=1;
	k=n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			printf("%d",j);
		}
		printf("\n");
		for(s=1;s<=m;s++)
		{
			printf(" ");
		}
		k--;
		m++;
	}
}


