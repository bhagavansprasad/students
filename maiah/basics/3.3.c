#include <stdio.h>
main()
{
	int i,n=13,c;
	for(i=2;i>=n;i++)
	{
		c=n%i;
		if(c==0)
		break;
	}
	if(c=!0)
	printf("it is a prime numder");
	else
	printf("it is not a prime number");
}
