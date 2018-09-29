#include<stdio.h>
main()
{
	int n=5,i=1,j,c=-1,k,l;
	for(n=5;n>0;n--)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",j);
		}
		c++;
		if(n<5)
		{
			for(k=1;k<=c;k++)
			{
				printf(" ");
			}
			printf("%d",n);
			c++;
		}
		for(l=(n-1);l>0;l--)
		{
			printf("%d",l);
		}
		printf("\n");
	}
}
