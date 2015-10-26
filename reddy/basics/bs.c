#include "stdio.h"
int main()
{
int a[100]={5,4,3,2,6},c,d,s,n=5;
for(c=0;c<n;c++)
	{
	for(c=0;c<(n-1);c++)
		{
			for(d=0;d<n-c-1;d++)
			{
			if(a[d]>a[d+1])
				{
				s=a[d];
				a[d]=a[d+1];
				a[d+1]=s;
				}
			}
		}
		printf("sorted list in asendingorder is:\n");
		for(c=0;c<n;c++)
		printf("%d\n",a[c]);
		return(0);
	}
}
