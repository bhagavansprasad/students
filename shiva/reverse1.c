#include<stdio.h>
main()
{
	int i=1,n,l,ref = 5;
	for(n=ref;n>=1;n--)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d",i);
		}
		if(i == ref+1)
		{
			i--;
		}
		else
		{
			for(l=1;l<((ref-n)*2);l++)
			{
				printf(" ");

			}
		}
		for(i=i-1;i>=1;i--)
		{
			printf("%d",i);

		}
		printf("\n");
	}
}

