#include<stdio.h>
int main()
{
	int n=6,i,j,a,b,c;
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ;j<=(n-i-2) ; j++)
		{
			printf(" ");
		}

		for(j=0; j<=i ; j++)
		{
			a=fact(i);
			b=fact(j);
			c=fact(i-j);
			printf(" %d",(a/(b*c)));
		}

		printf("\n");
	}
}

int fact(int n)
{
	int i,fact=1;
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
	}
	return fact;
}
