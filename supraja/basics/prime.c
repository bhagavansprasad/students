#include <stdio.h> 
main()
{
	int n=25,i=2;
	while(i<n)
	{
		if(n%i==0)
		{
			printf("not prime\n");
			break;
		}
		i++;
	}
	if(i==n)
	{
		printf("prime\n");
	}
}


