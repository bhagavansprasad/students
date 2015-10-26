#include <stdio.h>
int main()
{
	int i;
	int a;
	int n;
	int c = 1;
	int cp = 1;
	int sp = 2;
	printf ("Enter no. of prime numbers sum : ", n);
	scanf ( "%d", &n);
	for ( i = 3; i; i++)
	{
		if (cp >= n)
		{
			break; 
		} 
                c=1;
		for ( a = 2; a <= i/2; a++)
		{
			if ( i % a == 0)
			{
				c = 0;
				break;    
			} 
		}
		if (c != 0)
		{
			cp++;
			sp = sp + i;
		}

	}              
	printf ( "sum of first %d prime numbers is %d\n", n, sp);  
}
