#include "flv.h"
int power=1;
int offset_value(int n)
{
	int b = 0, d = 0;
	b = decimaltobinary(n);
	d = binarytodecimal(b);
	return d;
}

int decimaltobinary(int n)
{
	int rem, i = 1, binary=0;
	while (n!=0)
	{
		rem = n%2;
		n/=2;
		binary+=rem*i;
		i*=10;
	}
	return binary;
}

int binarytodecimal(int n)
{
	int rem, d, j,dec = 0;
	for(j = 1; n > 0; n/=10, j*=2)
	{
		rem = n%10;
		d = rem*j;
		dec+=d;
	}
	return dec;
}

int convert_hex_to_bin(char c)
{
	int mask=1,n,i,sum=0;
	printf("c -- %d\n", c);
	for(i=0;i<=7;i++)
	{
		n = c&(mask<<i);
		if(n>0)
		{
			if(power == 1)
			{
				printf("power is 1");
				sum = sum +1;
			}
			else
			{
				sum = sum+power;
			}
		}
		power=power*2;

		printf("n--%d\n",n);
		printf("sum--%d\n", sum);
		//printf("sum--%d\n",mask<<i);
	}
	return sum;
}
