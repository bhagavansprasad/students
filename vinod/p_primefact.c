#include <stdio.h>
#define N 8   
int is_prime(int );
int fact(int );
int main()
{
	int fval=0,flag=0;
	
	flag=is_prime(N);
	fval=fact(N);
	
	if(flag == 1)
		printf("%d is prime number\n",N);
	else
		printf("%d is not prime number\n",N);
	
	printf("Factorial of %d is --> %d\n",N,fval);
	
	return 0;

}
