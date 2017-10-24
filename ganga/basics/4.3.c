#include<stdio.h>
void main()
{
	int i,j,temp=0,a[5]={9,8,5,4,4};
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{  
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		printf("%d",a[i]);
	}
}
