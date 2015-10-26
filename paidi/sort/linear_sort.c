#include<stdio.h>
main()
{
	int arr[]={1,2,24,4,5,66,7,6,3,66,88};
	int i,num=88,n=11;
	for(i=0;i<n;i++)
	{
		if(arr[i]>=num)
		{
			if(arr[i]==num)
				printf("position is ok-->=%d\n",i);
			else
				printf("position is not ok\n");
			break ;
		}
	}

}
