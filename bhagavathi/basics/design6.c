#include<stdio.h>
main()
{
	int i,j,g=5,z,k,n=5,m=1,s,p=4;
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
		p--;
		for(k=5;k<=1;k++)
		{
			for(z=1;z>=g;z--)
			{
				printf("%d",z);
			}
		}
		m++;
		g--;
		printf("\n");
	}
}
