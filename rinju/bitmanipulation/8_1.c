#include<stdio.h>
main()
{
	int n=0x11011101,count;
	while(n)
	{
		n=n&(n-1);
	++count;
	}
	printf("%d",count);
}
