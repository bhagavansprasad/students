#include<stdio.h>
main()
{
int i,j,n=5;
for(i=0;i<n;i++)
{
for(j=0;j<i;j++)
{
printf(" ");
}
for(j=1;j<(n-i);j++)
{
printf("%d",j);
}
printf("\n");
}
}

