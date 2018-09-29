#include"stdio.h"
main()
{
int i,j,t,n=6,a[10]={5,8,10,1,2,4};
for(i=0;i<n;i++)
{
for(j=0;j<(n-1)-i;j++)
{
if(a[j]>a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}
}
printf("the sorted list");
for(i=0;i<n;i++)
{
printf("%4d\n",a[i]);
}
}

