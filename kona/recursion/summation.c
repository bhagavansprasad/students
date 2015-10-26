#include <stdio.h>
main()
{
	int n=20;
	printf("%d\n",summation(n));
}
int summation(int n)
{
	if(n==0)
	return 0;
	return(n+summation(n-1));
}
