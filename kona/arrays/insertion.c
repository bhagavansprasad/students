#include <stdio.h>
main()
{
	int i,j,k,n=5;
	int a[5]={44,55,33,11,22};
	for(i=1;i<n;i++)
	{
		k=a[i];
		for(j=i-1;j>=0 && k<a[j];j--)
			a[j+1]=a[j];
			a[j+1]=k;
	}
	for(i=0;i<n;i++)
		printf("array val is :%d\n",a[i]);

}

