#include<stdio.h>
main()
{
	int i,j,a[]={10,23,43,56,24,65},n=6;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i]<a[j])
				a[i]=a[j];
				printf("%d\n",a[i]);
		}
		printf("%d\n",a[i]);
	}
}
