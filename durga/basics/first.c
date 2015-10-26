#include<stdio.h>
main()
{
  int n=5,num;
  for(num=2;num<n;num++)
  {
   if(n%num==0)
   {
     printf("not a prime");
	} 
  }
  printf("prime no");
  return(0);
}

