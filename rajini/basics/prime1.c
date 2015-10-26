#include <stdio.h>
main()
{
  int n=26,i=2,flag=0;
   for(i=2;i<n/2;i++)
    {
	  if(n%i==0)
	    {
		  flag=1;
		}
	}
      if(flag==0)
       printf("not prime\n");
	   else
	   printf("prime \n");
}
