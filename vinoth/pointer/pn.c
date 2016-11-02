#include<stdio.h>
int main()
{
	int i=0, n=23, flag = 0, j=0, c=0;
	for(j=2; c<=n; j++)
	{
		for(i=2; i<=j-1; i++)
		{
			if(j%i==0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		//if(i==j)
		{
			printf("%d\n",j);
			c++;
		}
	}
}


