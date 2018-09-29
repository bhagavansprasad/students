#include<stdio.h>
main()
{
 int i,j,n=5,k,a;
 system("clear");
 a=n;
 for(i=1;i<=n;i++)
 {
    for(k=1;k<i;k++)
       printf(" ");
    for(j=a;j>=1;j--)
       printf("%d",j);
  a--; 

 printf("\n");
  }

}
 
