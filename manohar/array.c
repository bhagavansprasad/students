/*
   2-----------2
   3-----------1
   4-----------1
   0-----------2
   0-----------1
 */
#include<stdio.h>
int main()
{
	int a[5]={2,3,4,2,0};
	int i,j,count=1;
	for(i=0;i<=4;i++)
	{
		count=1;
		for(j=i+1;j<=4;j++)
		{
			if(a[i]==a[j])
			{
				a[j]=0;
				count++;
			}
		}
		if(count!=0)	
			printf("%d-----------%d\n",a[i],count);

	}
	if(count!=0)	
		printf("%d-----------%d\n",a[i],count);
return 0;		
}
