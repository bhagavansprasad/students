#include <stdio.h>
main()
{
	int i,j,n=5,t,p,q,sp=1;
	p=n;q=n;
	for(i=0;i<n;i++)
	{
		for(j=1;j<=p;j++)
		{
			printf("%d",j);
		}
		if(i>0)
		{
			for(j=1;j<=sp;j++)
			{
				printf(" ");
			}
			sp=sp+2;
		}
		for(j=q-1;j>=1;j--)
		{
			printf("%d",j);
		}
		if(i>0)
			q--;
		p--;
		printf("\n");
	}
}
