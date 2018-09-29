#include <stdio.h>
main()
{
	int n=10,item=30,t;
	int a[10]={12,15,18,21,24,27,30,33,36,39};
	t=binary(a,n,item);
	if(t==-1)
	printf("element is not found :%d\n",item);
	else
	printf("element is found :%d\n",item);
}
int binary(int a[],int n,int item)
{
	int low=0,up=n-1,mid;
	while(low<=up)
	{
		mid=(low+up)/2;
		if(item>a[mid])
		low=mid+1;
		else if(item<a[mid])
		up=mid-1;
		else
		return mid;
	}
	return -1;

}
