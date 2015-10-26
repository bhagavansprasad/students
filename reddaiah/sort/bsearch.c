#include"stdio.h"
main()
{
int n=10,t,item=12;
int a[10]={9,10,12,14,15,16,21,22};
t=bsearch(n,a,item);
if(t==-1)
printf("%d element is not found",item);
else
printf("%d%d\n element is found",item,t);
}
int bsearch(int n,int a[-1],int item);
{
int low=0,mid,up=n-1;
mid=(low+up)/2;
while(low<=up)
{
if(item>a[mid])
low=mid+1;
else if(item<a[mid])
up=mid-1;
else
return mid;
}
return -1;
}


