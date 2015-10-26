#include<stdio.h>
main()
{
	int n=5,i,k=0,j;
	for(i=1;i<=n;i++)
	{
		printf("%d",i);
		if(i==n)
		{
			printf("\n");
			i=0;
			n--;
			k++;
		
		for(j=1;j<=k;j++)
		{
			printf("\n");
		}
		}
	}
}
