#include<stdio.h>
int is_prime(int p)
{
 int flag=0,i;
 for(i=2;i<p;i++)
 {
  if(p%i==0)
  {
   flag=1;
   break;
   }
  }
  if(flag==1)
  return(1);
  else 
  return(0);
}
main()
{
int totl=0,count=0,n=100,i,t;
while(count<n)
 {
  for(i=2;i<n,i++)
  {
   t=is_prime(i);
   if(t==1)
   totl+=i;
  }
  count++;
}
ptintf("%d",total);
}
