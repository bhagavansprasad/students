#include<stdio.h>
main()
{
	int i=2,n=8,c;
	for(i=2;i<n;i++)
{
	c=n%i;
	if(c==0)
	{
		printf("%d n is not a prime number\n",n);
		if (c!=0)
			continue;
	}
	if(i==n)
		printf("%d n is a prime number\n",n);
	if(i<n)
		printf("%d n is not a prime number\n",n);
}
}
