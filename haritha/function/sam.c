#include <stdio.h>
main()
{
	//int reverse(int);
	int n=5,reverse;
	reverse(n);
	//return 0;
}
int_reverse(int n)
{
	if(n==0)
		return 0;
	else
		printf("%d",n);
	reverse(--n);
}
