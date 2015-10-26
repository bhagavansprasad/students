#include<stdio.h>
main()
{
int i=0,j=0,k=0,n=5;
for(i=0;i<=n;i++)
{
for(j=1;j<=i;j++)
{
printf(" ");
}
for(k=1;k<=(n-i)+1;k++)
{
printf("%d",k);
}
printf("\n");
}
}
