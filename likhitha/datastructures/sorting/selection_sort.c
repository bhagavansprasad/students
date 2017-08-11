#include <stdio.h>
main()
{
	int a[5]={7,2,9,0,5};
	int i , j , n=5 , temp=0;
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
}
