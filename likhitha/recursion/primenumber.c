#include<stdio.h>

int main()
{
	int num=15,a , b = 2;

	a = isPrime(num, b);

	if(a==0)
		printf("%d is a prime number\n",num);
	else
		printf("%d is not a prime number\n",num);
	printf("\n");
}

int isPrime(int num, int i)
{
	if( num == 1)
		return 1;

	else if( num % i == 0 && num == i)
		return 0;

	else if( num % i == 0)
		return 1;

	else
		return isPrime(num, i+1);

}
