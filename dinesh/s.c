#include <stdio.h>
main ()
{
	int i , n = 6 , s=0, fact = 1;
	for (i = 1; i <= n; i++)
	{
		fact = fact * i;
		s = s+fact;
	}
	printf("%d", s);
}
