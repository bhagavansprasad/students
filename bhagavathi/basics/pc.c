#include<stdio.h>
main()
{
int n=7,c=1;
c=prime (n);
if(c==0)
{
printf("this is prime number%d\n",c);
}
}
int prime (int a)
{
	int n,k,f=1;
	for(k=1;k<=a;k++)
	{
		if(n%k==0)
		{
		f=0;
		}
	}
	return f;
}
