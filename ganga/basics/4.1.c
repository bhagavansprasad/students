#include<stdio.h>
void main()
{
	int i,j,a[5]={2,1,3,2,3};
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(a[i]==a[j])
			{
				a[j]=0;
			}
		}
		printf("%d",a[i]);
	}
	printf("\n");
}
