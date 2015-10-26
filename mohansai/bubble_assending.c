#include "stdio.h"
main()
{
int n=8;
int a[8]= {10,2,30,5,6,7,9,25};
int i,j,k,temp=0;

for(i=0;i<n;i++)
	{
	for(j=0;j<n-1;j++)
	{
		if(a[j]>=a[j+1])
		{
			temp=a[j+1];
			a[j+1]=a[j];
			a[j]=temp;
			
		}
	
	}



//printf("%d\n",a[i]);
}
for(k=0;k<n;k++)
printf("%d\n",a[k]);


}
