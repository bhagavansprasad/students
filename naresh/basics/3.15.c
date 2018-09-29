#include<stdio.h>
main()
{
	int n=5,i=0,j=0,k=0,l=0;
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		for(k=1;k<=2*(n-i)-1;k++)
		{
			printf(" ");
		}
		for(l=i;l>=1;l--)
		{
			printf("%d",l);
		}
	
	printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		printf("%d",i);
	}
	for(j=4;j>=1;j--)
	{
		printf("%d",j);
	}

}
