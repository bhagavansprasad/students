#include <stdio.h>
main()
{
	int a = 300;
	int i = 0;
	char *p = ((char *)&a);
    printf ( "Address of a : %u ", &a );
	for ( i=0; i < sizeof (int); i++ )
		printf (" %02d ", *(p + i));	
}
