#include <stdio.h>
//void palindrome (int a);
void main()
{
	palindrome(624);
}

int palindrome(int a)
{
	int n, i, c = 0;
	n = a;

	for(i = 0; i < 3; i++)
	{
		c = c * 10 + a % 10;
		a = a / 10;
	}

	printf("c :%d\n", c);

	if(n == c)
	{
		printf("palindrome \n");
	}

	else
	{
		printf("not a palindrome \n");
	}
}

