#include<stdio.h>
int main()
{
	int i,j,n=9,f=0;
	for(i=1;i<=n;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			printf("%d\n",i);
		}
		f=0;
	}
}
