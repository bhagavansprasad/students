#include<stdio.h>
main()
{
	int i,j,k,n=5,m,s,p=0;
	m=n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%d",j);
		}
		for(s=1;s<=p;s++)
		{
			printf("  ");
		}
		p++;
		k=j-1;
		for( ;k>=1;k--)
		{
			printf("%d",k);
		}
		
		m--;
		printf("\n");
	}
}
