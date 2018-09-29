#include <stdio.h>
int main()
{
	int p,n=8;
		p=is_prime(n);
	if(p==0)
		printf("not prime");
	else
		printf("prime");
}
int is_prime(int num)
{
	int i,t;
	for(i=2;i<=num-1;i++)
	{
		t=num%i;
		if(t==0)
		{
			return 0;
		}
		break;
	}
	if(t!=0)
	{
		return 1;
	}
}
