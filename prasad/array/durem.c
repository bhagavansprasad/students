#include"stdio.h"
main()
{
	int i,j,k,l,c=6;
	int a[]={1,2,3,1,4,3,1};
	for(i=0;i<c;i++)
	{
		for(j=i+1;j<c;j++)
		{
			if(a[i]==a[j])
			{
				for(k=j;k<c;k++)
				{
					a[k]=a[k+1];
				}
				c--;
				j--;

			}
		}	
printf(" \n");
                  for(l=0;l<c;l++)
		{
			printf("a[%d]=%d \n",l,a[l]);
			}
}
}
