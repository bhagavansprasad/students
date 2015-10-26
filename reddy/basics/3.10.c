#include<stdio.h>
main()
{
int i,n=5,j,k;
for(i=1;i<=n;i++)
{
for(j=1;j<=(n-i+1);j++)
{
printf("%d",j);
}
printf("\n");
for(k=i;k>=1;k--)
{
printf("-");
}
}
}
