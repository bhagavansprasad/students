#include <stdio.h>
main()
{
	int i,j,tmp,n=5;
	int a[5]={44,55,33,11,22};
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("array val is :%d\n",a[i]);
}


