#include<stdio.h>

char* astrncpy ( char *d , const char *s , int n )
{
	int i;

	for ( i=0; i<n && s[i] != '\0'; i++ )
	{
		d[i] = s[i];
	}
	d[i] = '\0';

	return(d);
}
