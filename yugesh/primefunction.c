#include <stdio.h>
int prime(int );
main()
{
	int i,n=11,count=0,a;
	a=prime(11);
	if(a==0)
		printf("prime number");
	if(a==1)
		printf("is not prime number");
}
int prime(int n)
{
	int i,count=0;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
			count++;
	}
	if(count==0)
		return 0;
	if(count==1)
		return 1;
}
