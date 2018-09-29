/* 1 2 3 4 5 4 3 2 1 */
#include<stdio.h>
main()
{
int i,j,n=5;
for(i=1;i<=n;i++)
{
for(j=1;j<=i;j++)
{
printf("%d",j);
}
printf("\n");
}
}
