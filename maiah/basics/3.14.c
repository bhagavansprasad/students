#include <stdio.h>
main()
{
	int i,j,n=5,space,k,l;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<n-i+1;j++)
		{
			printf("%d",j);
		}
		if(i==1)
		space=space+0;
		else
		if(i==2)
		space=space+1;
		else
		space=space+2;
		for(l=i;l>=space;l--)
		{
			printf(" ");
		}
		if(i<n-i)
		{
			for(k=4;k>=1;k--)
			{
				printf("%d",k);
			}
		}
		else
		for(k=n-i;k>=1;k--)
		{
			printf("%d",k);
		}
	printf("\n");
	}
}
