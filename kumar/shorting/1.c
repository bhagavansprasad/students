#include<stdio.h>
int main()
{
	int a[5]={22,33,11,53,43};
	int i=1,n=5,j=1,t,k=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			}
		}
	}
	while(k<n)
	{
		printf("%d\n",a[k]);
		k++;
	}
	
}

