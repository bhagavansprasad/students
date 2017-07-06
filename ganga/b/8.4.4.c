#include<stdio.h>
main()
{
	int c,d,n,a=8,m1=0xaa,m2=0x55;
	c=m1&a;
	d=m2&a;
	c=c>>1;
	d=d<<1;
	n=c|d;
	printf("%d",n);
}
