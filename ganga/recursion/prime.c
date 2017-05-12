#include <stdio.h>

int i = 2;
main()
{
	int retval = isprime(7);

	if(retval == 1)
		printf("not a prime number\n");

	else
		printf("prime\n");
}

int isprime(int n)
{
	if(n % i == 0) 
		return;

	if(i == n)
		return 0;	

	else
		return isprime(n % i+1);
}
