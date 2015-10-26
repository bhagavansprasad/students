#include <stdio.h>
main()
{
	int i,j,tmp,min,n=5;
	int a[5]={44,55,33,11,22};
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				min=j;
		}
		if(i!=min)
		{
			tmp=a[i];
			a[i]=a[min];
			a[min]=tmp;
		}
	}
	for(i=0;i<n;i++)
		printf("array val is :%d\n",a[i]);

}


