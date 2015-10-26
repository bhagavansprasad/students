#include "stdio.h"
#include "stdlib.h"
int main()
{
	int n = 10,a = 0, b = 1;
	febonacci(a,b,n);

return 0;
}

int febonacci(int a, int b, int n)
{
 	int c ;
	
	if(n==0)
		exit(1);
		
		c=a+b;
		a=b;
		b=c;	
	
	printf("%d\n",c);
	return(febonacci(a,b,n-1));
}

