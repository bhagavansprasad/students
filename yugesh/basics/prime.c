#include <stdio.h>
main()
{
	int i,n=11,count=0;
	for(i=2;i<11;i++)
	{
		if(n%i==0)
			count++;
	}
	if(count==0)
		printf("prime number\n");
	else
		printf("not a prime number\n");
}

