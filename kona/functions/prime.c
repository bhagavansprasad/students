#include <stdio.h>
main()
{
	int n=5;
	if(isprime(n))
	printf("prime\n");
	else
	printf("not prime\n");
	return 0;
}
int isprime(int n)
{
	int i;
	for(i=2;i<n;i++)
	if(n%i==0)
	return 0;
	return 1;
}
