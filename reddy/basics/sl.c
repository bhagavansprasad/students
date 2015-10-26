#include "stdio.h"
main()
{
int i,j,n=5,a[100]={5,4,6,1,8},p,s;
for(i=0;i<n;i++)
for(i=0;i<(n-1);i++)
{
p=i;
for(j=i+1;j<n;j++)
{
if(a[p]>a[j])
p=j;
}
if(p!=i)
{
s=a[i];
a[i]=a[p];
a[p]=s;
}
}
printf("the shorted list are:\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
return(0);
}
