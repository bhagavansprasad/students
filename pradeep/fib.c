#include <stdio.h>
int main()
{
	int a=0,b=1,c,n=7,i;
	for(i=0;i<=n;i++)
	{
		c=a+b;
		b=a;
		c=b;
		print("%d",c);
	}
}
