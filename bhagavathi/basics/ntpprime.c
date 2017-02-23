#include<stdio.h>
int prime(int a);
main()
{
	int i,n=10,c;
	for(i=2;i<=n;i++)
	{
		c=prime(i);
		if(c==1)
		{
			printf("this prime number %d\n",c);
		}
	}

	int prime(int a)
	{
		int b,f=1;
		for(b=2;b<=a-1;b++)
		{
			if(a%b==0)
			{
				f=0;
			}
			return f;
		}
	}	
}


