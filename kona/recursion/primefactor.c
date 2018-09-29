#include <stdio.h>
main()
{
	int n=84;
	printf("%d",pfactor(n));
}
int pfactor(int n)
{
	int i=2;
	if(n==1)
	return;
	while(n%i!=0)
	i++;
	printf("%d\t",i);
	pfactor(n/i);
}
