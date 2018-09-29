#include <stdio.h>
main ()
{
	int t, a=83390, b=9730;

	t = add (a, b);
	printf ("%d\n", t);

	t = sub (a, b);
	printf ("%d\n", t);

	t = mul (a,b);
	printf ("%d\n", t);

	t = div (a,b);
	printf ("%d\n", t);

	t = mod (a, b);
	printf ("%d\n", t);
}
