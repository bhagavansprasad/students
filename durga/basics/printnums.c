#include<stdio.h>
main()
{
    int i,j,m,k,n=5,p=7;

	  for ( i = 1; i <= n; i++)
	  {
	   for ( j = 1; j <= i; j++)
	   printf("%d",j);
	   for( k =1; k<=p; k++)
	   printf(" ");
	   if(i==5)
	   if(j==6)
	   j=j-1;
	  	   for( m =j-1; m > 0; m--) 
	   printf("%d",m);
	   p=p-2;
	   printf("\n");
	   }
	   }
