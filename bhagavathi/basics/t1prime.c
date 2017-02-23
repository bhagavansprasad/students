#include<stdio.h>
int prime(int);
main() 
{
	int i=3,z = 0,n=10,c,count=1;
	for(i=3;count<=n;)
	{
		c=prime(i);
		if(c==1)
		{
			z=i;
			z=z+i;
			count++;
		}
      i++;
	}
	printf("%d\n",z);
}
int prime(int a)
{
	int j=2,f=1;
	{
		for(j=2;j<=a-1;j++)
		{
			if(a%j==0)
			{
				f=0;
				}
			}
			return f;
		}
}
