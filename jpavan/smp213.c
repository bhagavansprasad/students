#include<stdio.h>
main()
{
int i,j;
for(i=1;i<=5;i++)
 	{
	 printf("%d",i);
	   for(j=0;j<=5;j++)
	      {
		   printf("%d",j);
		       if(j%2)
			   i+=2;
			} 
	}	
	printf("%d,%d\n",i,j);
}	
