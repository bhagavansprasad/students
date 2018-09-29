#include <stdio.h>
main()
{
int i=1,j,n=5,t;
t=n;
while(i<=n)
{
for(j=1;j<=t;j++)
{
printf("%d",j);
}
i++;
t--;
printf("\n");
}
}
