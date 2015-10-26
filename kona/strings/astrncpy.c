#include<stdio.h>

char* astrncpy ( char *d , const char *s1 , int n )
{
	int i;

	for ( i=0; i<n && s1[i] != '\0'; i++ )
	{
		d[i] = s1[i];
	}
	d[i] = '\0';

	return(d);
}
