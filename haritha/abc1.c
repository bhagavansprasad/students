#include <stdio.h>
main()
{
	int i,j,k,n=5,c=0,m=0;
	for(i=1;i<=n;i++)
	{
		if(i<=3)
		{
			for(j=m;j<=i;j++)
			{
				printf(" ");
			}
			for(k=65;k<=65+c;k++)
			{
				printf("%c",k);
			}for(j=m;j<=i;j++)
			{
				printf(" ");
			}
			c=c+2;
			m=m+2;
			printf("\n");
		}
	}
	c=c-4;
	m=m-4;
	for(i=1;i<=n;i++)
	{
		if(i<=2)
		{
			for(j=m;j>i;j--)
			{
				printf(" ");
			}for(k=65;k<=65+c;k++)
			{printf("%c",k);
			}
			for(j=m;j>i;j--)
			{
				printf(" ");
			}
			c=c-2;
           m=m+2;
		}
		printf("\n");
	}
}
