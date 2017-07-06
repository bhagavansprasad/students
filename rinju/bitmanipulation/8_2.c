#include<stdio.h>
main()
{
	int a=0x1101;
	int b=0x1111;
	int c,temp,n;
	n=a^b;
	while(n)
	{
		n=n&(n-1);
		c++;
	}
	temp=a;
	a=b;
	b=temp;
	printf("%x %x %d",a,b,c);
}
