#include <stdio.h>
int comb(int ,int);
int fcatorial(int);
main()
{
	int i,j,n=5;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		printf("%5d",comb(i,j));
		printf("\n");
	}
}
int comb(int n,int r)
{
	int c;
	c=factorial(n)/(factorial(r)*factorial(n-r));
	return c;
}
int factorial(int n)
{
	int fact=1,i;
	if(n==0)
	return 1;
	for(i=n;i>1;i--)
	fact=fact*i;
	return fact;
}
