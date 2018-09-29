
#include<stdio.h>

int setbit(int n, int pos)
{
	 return n = n | (1 << pos);
}

int main()
{
	unsigned int a=25;
	unsigned int b=6;

	showbits(a);
	a = setbit(a,b);
	showbits(a);
}
