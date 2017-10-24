#include<stdio.h>
void main()
{
	int i,j,k,n=5,a[5]={2,3,2,3,5};
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				for(k=j+1;k<5;k++)
				{
					a[j]=a[k];
					j++;
				}
				n--;
			}
		}
		printf("%d",a[i]);
	} 
	printf("\n");
}
