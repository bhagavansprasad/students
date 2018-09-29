#include <stdio.h>
main()
{
	int i=0,j=0,n=4,k=0;
	for(i=0;i<n;i++,k++)
	{
		if(k==1)
			k++;
		else if (k==n)
			k=1;
		for(j = n*k+1;j <= n*k+n;j++)
		{
			printf("%d",j);
			if(j < n*k+n)
				printf("*");
		}
		printf("\n");
	}
}
