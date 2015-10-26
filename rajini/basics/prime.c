#include <stdio.h>
main()
 {
   int n=5,i=2;
   for(i=2;i<n;i++)
   {
     if(n%i==0)
	 break;
    }
	  if(n==i)
	  printf("prime\n");
	  else
	  printf("not prime\n");
}
