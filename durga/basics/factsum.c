#include<stdio.h>
int fact_of(int n)
{
  int fact=1,c;
  for(c=1;c<=n;c++)
  {
    fact*=c;
	}
	return(fact);
 } 
main()
{
int s=0,n=7,i,f;
for(i=0;i<=n;i++)
{
 f= fact_of(i);
 s+=f;
}
printf("%d",s);
return(0);
}

