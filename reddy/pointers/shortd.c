#include <stdio.h>
main()
{
	int a = 300;
    short int b = 0;
	int i = 0;
	char *p = ((char *)&a);
	char *q = ((char *)&b);

		printf ( " Actual 4 bytes are : " );

	for ( i=0; i < sizeof (int); i++ )
	
         printf ( " \n                       %02d \n ", *( p + i ) );
	     
		 printf ( "Recomended bytes are : " );
	for ( i=0; i < sizeof (short int); i++ )

		printf ("\n       %02d \n ", *( q + i ) = *( p + ( sizeof ( int ) - ( i + 1 ) ) ));


}
