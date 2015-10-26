#include<stdio.h>
main()
{
 int i,n=5,x=2,y=1,t,s=0;
 for(i=0;i<=n;i++)
 {
  t=get_fact(x+i)/get_fact(y+i);
  printf("%d",t);
  s=s+t;
  printf("%d",s);
  }
 }
 int get_fact(int x) 
 {
  int j,f=1;
  for(j=1;j<=x;j++)
  {
   f=f*j;
   }
   return(f);
  } 
