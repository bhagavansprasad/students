#include<stdio.h>
main()
{
	int count=0,i,n=15;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			count++;
			break;
		}
	}
	if (count==0)
	{
		printf("prime number\n");
	}
	else
	{
		printf("not prime number\n");
	}
}

