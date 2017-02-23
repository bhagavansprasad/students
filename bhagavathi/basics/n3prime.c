#include<stdio.h>
int prime (int);
main()
{
	int n=,i=1,c,k;
	//co=1;
	while(i<=n)
	{
		for(k=2;k<=20;k++)
		{
			c=prime(k);
			if(c==0)
			{
				printf("%d\n",k);
			}
		}
		i++;
	}
}
int prime(int a)
{
	int i,f=0;
	for(i=2;i<=a-1;i++)
	{
		if(a%i==0)
		{
			f=1;
		}
	}
	return f;
}
