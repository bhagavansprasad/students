#include<stdio.h>

int main()
{
	int c, n = 4426;
	c = reverse(n);

	printf("reverse of %d is %d\n", n, c);
}
int reverse(int n)
{
	int i, a=4426, c = 0;

	for(i = 0 ; i <= 3 ; i++)
	{
		c = c * 10 + a % 10;
		a = a / 10;
	}

	return c;
}
