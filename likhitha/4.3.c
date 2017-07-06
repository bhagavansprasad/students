#include <stdio.h>
int main()
{
	int a[5]={5,4,2,6,3};
	int n=5,i,j,k;
	for(i=0 ; i<n ; i++)
	{
		for(j=i+1 ; j<n ;j++)
		{
			if (a[i]>a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
		printf(" %d",a[i]);
	}
	printf("\n");
}

