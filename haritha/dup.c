#include <stdio.h>
main()
{
int i,j,a[7]={2,4,6,6,8,1,4};
for(i=0;i<7;i++)
{
for(j=i+1;j<7;j++)
{
if(a[i]==a[j])
{
a[j]=0;
}
}
}
//printf("replace elements for duplicate");
for(i=0;i<7;i++)
{
printf("%d",a[i]);
}
}
