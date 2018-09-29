#include<stdio.h>
main()
{
	int n=5,i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			printf("not prime");
			break;
		}
	
	}
	if(n==i)
	{
		printf("prime");
	}
}

