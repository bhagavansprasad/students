#include <stdio.h>
int prime(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i == 0)
		 return 0;
	}
	if(n == i)
		return 1;
}
main()
{
	int n = 21;
	int a = prime(n);
	if(a)
		printf("%d is prime num\n", n);
	else
		printf("%d is not prime\n",n);
}
