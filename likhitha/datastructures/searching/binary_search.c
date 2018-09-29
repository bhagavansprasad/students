#include <stdio.h>
main()
{
	int a[5]={2,5,9,0,6};
	int n=5 , i , j , key=6 , temp=0;
	int first=0 , last=n-1 , mid , flag=0 ;
	for(i=0 ; i<n ; i++)
	{
		for(j=i+1 ; j<n ; j++)
		{
			if(a[i]>a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
		printf("%d ",a[i]);
	}
	printf("\n");
	for( i = 0 ; i < n; i++)
	{
		mid=(first+last)/2;

		if(key==a[mid])
		{
			flag=1;
			break;
		}
		
		else if(key>a[mid])
		{
			first=mid+1;
		}
		else 
			last=mid-1;
	}
	if(flag==1)
	{
		printf("%d is index\n",mid);
		printf("%d is found\n",key);
	}
	else
		printf("%d is not found\n",key);
}
