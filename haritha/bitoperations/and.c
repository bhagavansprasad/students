#include<stdio.h>

main()
{
	int a=10;
	int b=25;
	int c;
	c=a&b;
	printf("%d\n",c);
	show_bits(c);

}

int show_bits(int n)
{
	int i;
	for(i=7;i>=0;i--)
	{
		printf("%d",(n>>i)&1);
	}
}
