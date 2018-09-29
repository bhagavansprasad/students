#include<stdio.h>
main()
{
 int n=5,i,t=0,s=0;
 for(i=1;i<=n;i++)
 {
  t=get_fact(i+1)/get_fact(i);
  printf("%d\n",t);
  }
 }
 int get_fact(int n)
 {
  int f=1,j;
  for(j=1;j<=n;j++)
  {
   f=f*j;
   }
   return(f)
}
