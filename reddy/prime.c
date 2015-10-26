#include <stdio.h>
int main()
{
	int a;
	int n;
	int c = 0;
         printf("enter num to find whether it is prime or not : ");
        scanf("%d", &n);  
	for ( a = 2; a <= n/2; a++)
	{
		if ( n % a == 0 )
		{	
			c = 0;
			break;
		}
		else
			c++;
	}
	if ( c != 0 )
		printf (" %d is PRIME\n", n);
	else 
		printf ("%d is NOT PRIME\n", n);
}
