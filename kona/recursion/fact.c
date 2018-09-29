#include <stdio.h>
main()
{
	int num=5,t;
	t=fact(num);
	printf("%d\n",t);
}
int fact (int n)
{
	if(n==0)
	return 1;
	return(n*fact(n-1));
}
