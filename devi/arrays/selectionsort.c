#include <stdio.h>
main()
{
int i,j,n=5,t,k;
int a[]={6,5,9,2,3};
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
for(k=0;k<n;k++)
printf("%d",a[k]);
printf("\n");
}
for(i=0;i<n;i++)
printf("%d",a[i]);
}
