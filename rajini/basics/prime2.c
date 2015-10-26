#include <stdio.h>
main()
{
	int x=8,t=0;
	t=is_prime(x);
	if(t==0)
	{
		printf("prime\n");
	}
	else
		printf("not prime");
}
int is_prime(int n)
{
int i=0;
	for(i=2;i<=n;i++)
{
	if(n%i==0)
		break;
}
if(n==i)
	return 0;
	else
	return 1;
}
