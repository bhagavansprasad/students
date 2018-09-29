#include<stdio.h>
main()
{
	int n=5,i;
	for(i=1;i<=n;i++)
	{
		printf("%d",i);
		if(i==n)
		{
			printf("\n");
			i=0;
			n--;
		}
	}
}
