#include <stdio.h>
#define decode(s,t,u,m,p,e,d) m##s##u##t
#define begin decode(a,n,i,m,a,t,e)
int begin()
{
 	int a=10,b=10,sum;
	sum = a+b;
	printf("sum-->%d\n",sum);
 printf(" helloworld ");
}
