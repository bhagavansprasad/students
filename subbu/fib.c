#include<stdio.h>
int main()
{
	int f=1,i,j,n=7;
	for(j=1;j<=n;j++)
	{
		for(i=1;i<=j;i++)
			f=f*i;
			printf("%d\n",f);
	}
}
