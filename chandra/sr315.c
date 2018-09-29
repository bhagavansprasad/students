#include<stdio.h>
main()
{
	int i,j,k,l,n=5,c=8;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		c--;
		for(k=1;k<=c;k++)
		{
			printf(" ");
		}
		if(j>n)
		{
			j--;
		}
		j--;
		for(l=j;l>0;l--)
		{
			printf("%d",l);
		}
		printf("\n");
		c--;
	}
}
