#include <stdio.h>
int main();
{
	int n=9,i;
	for(i=2;i<=n;i++)
	{
		if(n%i==0)
			break;
	}
	if(i==n)
	printf("%d is a prime number",n);
	else
		printf("%d is not a prime number",n);
}
