#include<stdio.h>

unsigned int getbits(unsigned int x,int p,int n)
{
	return (x >> (p+1-n)) & ~(~0 <<n);
}
main()
{
	printf("%d  \n",getbits(10,4,3));
}

