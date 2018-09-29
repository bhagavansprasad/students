#include"stdio.h"
main()
{
	int a[]={3,0,4,10,2,5,6,7,8,9,12,11,14,1,15},l,i,j,k,n=15,m;
	for(j=1;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(j==a[i])
				break;
		}
		if(j!=a[i])
		{
			k=j;
			break;
		}
	}
	for(l=0;l<n;l++)
		printf("%d ",a[l]);
	printf("\r\n");
	printf("MISSING NUMBER=%d \n",k);
}
