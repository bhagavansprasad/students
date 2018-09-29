#include<stdio.h>
main()
{
	int n=100,x,i=0,sum=0,k,a=0;
	for(i=0;i<500;i++)
	{
		int a=0,x=0;
		k=n;
		for(;n>0;)
		{
			x = n%10;
			a = a+x*x*x;
			n = n/10;

		}

		n=k;
		if(a == k)
		{
			n++;
			printf("a=%d\n",a);
		}
		else
			n++;
	}
}
