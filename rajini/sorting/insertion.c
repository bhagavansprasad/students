#include <stdio.h>
main()
{
	int a[20]={3,6,5,2,4,1};
	int i,j,t,n=6;
	for(i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		while((t<a[j])&&(j>=0))
				{
				   a[j+1]=a[j];
				   j= j-1;
				}
				a[j+1]=t;
	}
				printf("sorted");
				for(i=0;i<n;i++)
				{
			      	printf("%4d\n",a[i]);
				}
				return 0;
}

