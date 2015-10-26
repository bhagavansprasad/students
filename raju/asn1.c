#include<stdio.h>
main()
{
	int i,j;
	for(i=1;i<=5;i++)
	{
	 for(j=i-4;j<=i;j++)
	 {
	  if(j<=0)
	   {
	   printf(" ");
	   }
	   else
	   {
	   printf("%d",j);
	   }
	  }
	  printf("\n");
	}  
}	  

