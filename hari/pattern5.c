#include<stdio.h>
main()
{
 int i, j, n = 5,k = n;
 for(i = 0;i < n;i++,k--)
 { 
  for(j=k+1;j < n+i;j++)
  {
   printf(" ");
   }
   if(i=0)
   {
    for(j=1;j<k;j++)
	{
	printf("j");
	}
   }
   else
   {
	   for(j=1;j<=k;j++)
	   {
		   printf("j");
	   }
   }
   for(j=k;j>0;j--)
   {
	   printf("j");
   }
   printf("\n");
  }
  }

