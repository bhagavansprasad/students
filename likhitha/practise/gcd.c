#include<stdio.h>
int main()
{
	int n1=4, n2=8;
	/* 
	   int i, gcd;
	   for(i=1; i <= n1 && i <= n2; i=i+1)
	   {
	   if(n1%i==0 && n2%i==0)
	   gcd = i;
	   }

	   printf("%d\n",gcd);
	 */

	while(n1!=n2)
	{
		if(n1 > n2)
			n1 = n1- n2;

		else if (n2 > n1)
			n2 = n2- n1;
	}
	printf("%d\n",n1);
}

