#include<stdio.h>
main()
{
	int a=0,i,j,k,l,m,n=5;
	m=n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%d",j);
			for(l=0;l<=8;l+2)
			{
				a=l+1;
				printf(" ");
			}
		}
		k=j-1;
		for( ;k>=1;k--)
		{
			printf("%d",k);
		}
		m--;
	}
	printf("\n");
}
