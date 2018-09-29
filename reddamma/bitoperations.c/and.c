#include <stdio.h>
main()
{
	int a=10,b=8;
	int c,t;
	c=a|b;
	printf("c-->%d\n",c);
	t= showbits(c);
}
int  showbits(int n)
{
	int i;
	for(i=7;i>=0;i--)
	{
		printf("%d",(n>>i)&1);
	}
}

