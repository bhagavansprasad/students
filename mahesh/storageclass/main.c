#include<stdio.h>
int fact(int);
int isprime(int);
main()
{
	int n=4,m=5,a,b;
	a=fact(n);
	b=isprime(m);
	printf("fact %d/n",a);
	if(b==0)
	 printf("%d is pn/n",m);
	else
	 printf("%d is np/n",m);
}
