#include <stdio.h>
main()
{
int n=6,p=n+2,k,i,j;
for(k=1;k<=n;k++)
 {
  for(i=1;i<=k;i++)
  {
   printf("%d",i);
   }
   for(j=1;j<=p;j++)
   {
    printf(" ");
	}
	if(k==6)
	{
	
	if(i==7)
	{
	i=i-1;
	}
	}
	for(j=i-1;j>0;j--)
	{
	 printf("%d",j);
	 }
	 p=p-2;
	 printf("\n");
	 }
	 }
