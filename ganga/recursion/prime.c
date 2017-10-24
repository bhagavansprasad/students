#include <stdio.h>

int i = 2;
main()
{
	int retval = isprime(9);

	if(retval == 1)
		printf("not a prime number\n");

	else
		printf("prime\n");
}

int isprime(int n)
{
	if( n == 0 || n == 1)
		return 1;
	
	else if(n % i == 0 && n == i) 
		return 0;

	else if(n % i == 0)
		return 1;	

	else
		return isprime(n % i+1);
}
