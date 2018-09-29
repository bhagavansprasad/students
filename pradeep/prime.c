#include <stdio.h>
int main()
{
	int i,n=7,t;
	for(i=2;i<=n-1;i++)
	{
		t=n%i;
		if(t==0)
		{
			printf("not prime");
			break;
		}
	}
	if(t!=0)
	{
		printf("prime");
	}
}
