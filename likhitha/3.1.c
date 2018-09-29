#include <stdio.h>
int main()
{
	int first=-1,second=1,third,i,n=10,sum=0;
	for(i=1;i<=n;i++)
	{
		third=first+second;
		sum=sum+third;
		first=second;
		second=third;
	}
	printf("%d\n",sum);

	
}
