#include <stdio.h>
main()
{
	int a=5,b=6,c=7,t=0;
	int fact=1;
	t=factorial(a);
	printf("%d\r\n",t);
	t=factorial(b);
	printf("%d\r\n",t);
	t=factorial(c);
	printf("%d\r\n",t);
}
int factorial(int n)
{
	int f=1,i=0;
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
	return f;
}
