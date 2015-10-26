#include<stdio.h>
int main()
{
	int i,j,s=7,temp;
	int a[20]={1,3,2,6,3,4,2};

	for(i=1;i<s;i++)
	{
		temp=a[i];
		j=i-1;
		while((temp<a[j])&&(j>=0))
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}

	printf("After sorting: ");
	for(i=0;i<s;i++)
		printf(" %d",a[i]);
	printf("\n");
	return 0;
}

