#include<stdio.h>
main()
{
	int i,j,n=5,k,c=0;
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		printf("\n");
		c++;
		for(k=1;k<=c;k++)
		{
			printf(" ");
		}
	}
}
