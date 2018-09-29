#include<stdio.h>
main()
{
	int i,j,n=5;
	for(i=2;i<=n;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
				break;
			else
			{
				printf("%d",i);
			}
			break;
		}
	}
	}

