#include <stdio.h>

int decTobin(int n);
int main() 
{
	int decimal = 5;

	printf("Enter a decimal number%d\n ", decimal);
	printf("Binary number of %d is %d\n ", decimal, decTobin(decimal));

	return 0;
}

int decTobin(int n) 
{
	int remainder; 
	int binary = 0, i = 1;

	while(n != 0) 
	{
		remainder = n % 2;
		n = n / 2;
		binary = binary + (remainder * i);
		i = i * 10;
	}

	return binary;
}
