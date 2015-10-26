#include<stdio.h>
int main()
{
	int num,i=1,f=1,r,sum=0,temp;
	int min=1,max=1000;
	for(num=1; num <= 1000; num++)
	{
		temp = num;

		while(temp)
		{
			i=1;
			f=1;
			r=temp%10;

			while(i<=r)
			{
				f=f*i;
				i++;
			}
			sum=sum+f;
			temp=temp/10;
		}

		if(sum==num)
			printf("%d ",num);
	}
}
