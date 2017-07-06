#include<stdio.h>
int main()
{
	int n1=2, n2=4, a;
	a=gcd(n1,n2);
	printf("%d\n",a);
}
/*
   int gcd(int x,int y)
   {
   while(x!=y)
   {
   if(x>y)
   return gcd(x-y,y);
   else
   return gcd(x,y-x);
   }
   return x;
   }
 */

int gcd(int x,int y)
{
		if(x==0)
			return x;
		else if(y==0)
			return y;
		else if(x!=y)
			return(y,x%y);
}
