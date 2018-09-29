#include<stdio.h>
int a[]={5,7,9,2,3,10,20,30,7,8,71,8,90};
main()
{
	int flag;
	flag=binary_search(10);
	if(flag == 1)
	{
		printf("found\n");
	}
	else
	{
		printf("not found\n");
	}
}
binary_search(int n)
{

	int mid,n1;
	n1=sizeof(a)/4;
	mid=n1/2;
	printf("Total Numbers are = %d\n",n1);
	printf("Middle value  = %d\n",mid);
	int i,j;
	for(i=0;i<=mid-1;i++)
	{
		if(a[i]==n)
		{
			return 1;
		}
	}
	for(j=mid;j<=n1;j++)
	{
		if(a[j]==n)
		{
			return 1;
		}
	}
	return 0;
}

