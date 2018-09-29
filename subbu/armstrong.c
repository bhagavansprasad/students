#include <stdio.h>

int main()
{
	int i,r,sum,temp;
	int n=500;
	for(i=1;i<=n;i++)
	{
		temp=i;
		sum = 0;

		while(temp!=0)
		{
			r=temp%10;
			temp=temp/10;
			sum=sum+(r*r*r);
		}
		if(sum==i)
			printf("%d \n", sum);
	}

	return 0;
}
