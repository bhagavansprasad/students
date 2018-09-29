#include <stdio.h>
int linear(int a[],int pos,int item);
main()
{
	int t,pos=7,item=12;
	int a[7]={10,5,12,95,47,12,45};
	t=linear(a,pos,item);
	if(t==-1)
	printf("the element is not found\n");
	else
	printf("the element is found:%d\n",item);
}
int linear(int a[],int pos,int item)
{
	int i;
	for(i=0;i<pos;i++)
	{
		if(item==a[i])
		return i;
	}
	return -1;
}
