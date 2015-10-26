#include "stdio.h"
main()
{
	int n=10,s=0,i,x;
	for(i=2;i<=n;i++)
	{
		x=is_prime(i);
			if(x!=0)
			{
				s=s+i;
				printf("%d\n",s);
				
			}
	
	}
}
int is_prime(int i)
{
	int j;
	for(j=2;j<=i-1;j++)
	{
		if(i%j==0)
			break;
	}
	if(j==i)
		return (1);
	else
		return (0);
}
