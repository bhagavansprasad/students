#include<stdio.h>
int main()
{
	int i=100,n=999,cube,d,sum=0;
	for(i=100;i<=999;i++)
	{
		while(n>0)
		{
			d=n%10;
			n/=10;
			cube=d*d*d;
			sum=sum+cube;
		}
		if(i==sum)
			printf("%d\n",i);
	}
}
