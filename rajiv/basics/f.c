#include <stdio.h>
main()
{
int n=19,i,j=0;
for(i=2;i<n;i++)
{
 if(n%i==0)
 {
 j++;
 break;
 }
} 
 if(j==0)
 printf("prime number \n");
 else
 printf("not a prime number \n");
} 

