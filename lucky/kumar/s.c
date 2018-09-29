#include<stdio.h>
int main()
{
	int a=0,b=1,c,n=8,i;
	for(i=1;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
		printf("%d",c);
		printf("\n");
	}
}
