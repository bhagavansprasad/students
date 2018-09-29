#include<stdio.h>
int n=2,t=0;
main()
{
	int s=0,count=5,temp=0;
	while(t<count)
	{
	temp=is_prime(n);
	s=s+temp;
	n++;
	}
	printf("sum of %d prime numbers is %d\n",count,s);
}
int is_prime(int n)
{

	int i;
		for(i=2;i<n;i++)
		{
			if(n%i==0)
			{
				break;
			}
		}
		if(n==i)
		{
			t++;
			printf("temp-->%d\n",n);
			return n;
		}
		else
			return 0;
}
