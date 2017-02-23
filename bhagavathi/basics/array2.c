#include<stdio.h>
main()
{
	int sort[10]={23,3,4,5,66,78,78,8,999,99};
	int i,j,n=10,k=0;
	for(i=0;i<=n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(sort[i]>=sort[j])
			{
				k=sort[j];
				sort[j]=sort[i];
				sort[i]=k;
			}
		}
		printf("%d\n",sort[i]);
	}
}



