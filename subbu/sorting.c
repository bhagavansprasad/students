#include<stdio.h>
main()
{
	char a[10]={3,2,6,5,7};
	char j,x,i;
	for(i=1;i<=5;i++)
	{
		for(j=0;j<=5;j++)
		{
			if (a[i]>a[j])
			{
				x=a[i];
					a[i]=a[j];
					a[j]=x;
					printf("%d",i,j,x);
			}		
		}
	}
}

