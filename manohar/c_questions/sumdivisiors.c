#include <stdio.h>
main()
{
	int n=25,i,sum=0;
	int temp = n;
	for(i=1;i<=n-1;i++)
	{
		if(n%i==0)
		{
			sum = sum+i;
		}
	}
	if(temp == sum)
	printf("prefect number\n");
	else
	printf("Not prefect number\n");
}
