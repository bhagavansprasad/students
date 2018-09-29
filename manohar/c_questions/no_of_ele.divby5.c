#include <stdio.h>
int main()
{
	int n1=1,n2=100,i,sum = 0;
	for(i=n1;i<=n2;i++)
	{
		if(i%5==0)
		{
			sum ++;
		}
	}
	printf("sum  %d\n",sum);
	return 0;
}
