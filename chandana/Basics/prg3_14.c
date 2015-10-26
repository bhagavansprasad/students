#include<stdio.h>
main()
{
  int i,j,k,l,n=5,m,a;
  system("clear");
  a=n;
  for(m=1;m<=n;m++)
  { 
     for( i=1; i<=a; i++)
         printf(" %d ",i);
          
     for( k=n; k>=i; k--)
         printf(" - ");
     for(j=n-1; j>a; j--)
         printf(" - ");
     
     for(l=j;l>=1;l--)
        printf(" %d ",l);
     a--;
     printf("\n");
  }
}
