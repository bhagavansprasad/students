#include <stdio.h>
main()
{
	int n=5,i;
	for(i=0;i<5;i++)
	printf("%d\t",fib(i));
}
int fib(int n)
{
	if(n==0 || n==1)
	return 1;
	return(fib(n-1)+fib(n-2));
}
