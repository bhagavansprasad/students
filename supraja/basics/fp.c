#include<stdio.h>
 int main()
{
	int n=6;
	int x=is_prime(n);
	if(x==0)
		printf("np:%d\n",x);
		//printf("np");
	else
		printf("p:%d\n",x);
		//printf("p");
}
int is_prime(int n)
{
	int i;
	for(i=2;i<=n-1;i++)
	{
		if(n%i==0)
			break;
	}
	if(i==n)
		return (1);
	else
		return (0);
}

