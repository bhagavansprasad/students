#include <stdio.h>
main()
{
	int a=35,b=21;
	printf("%d\n",gcd(a,b));
}
int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
