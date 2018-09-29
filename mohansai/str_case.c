#include "stdio.h"

#include "string.h"

int astrncmp( char *name1 , char *name2 );

main()
{
	int i,n=4;
	char name1[] = "mohansai";
	char name2[] = "mohansai";

	i = astrncmp( name1 , name2 );

	printf("\n\n %d\n\n",i);
	
}

int astrncmp( char *name1 , char *name2 )
{
	int j;
	
	for( j = 0 ; name1[j] != '\0' && name2[j] != '\0' ; j++ )
	{
		
		if( name1[j] != name2[j] )
		
		{
		
			return ( name1[j] - name2[j]);
		

		}
	
	}	

	return ( name1[j] - name2[j]);
	
}
