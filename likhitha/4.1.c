#include <stdio.h>
int main()
{
	int a[10]={5,2,6,5,9,8,2,4,7,8};
	int n=10,i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1 ;j<n;j++)
		{
			if (a[i]==a[j])
			{
				a[j]=0;
				}
		}
		printf(" %d",a[i]);
	}
printf("\n");
}
