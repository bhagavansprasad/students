#include <stdio.h>
main()
{
int i,j,n=5;
j=n-1;
for(i=1;i<=n;i++)
{
printf("%d",i);
printf(" ");
if(i==n)
{
while(j>=1)
{
printf("%d",j);
printf(" ");
j--;
}
}
}
printf("\n");
}
