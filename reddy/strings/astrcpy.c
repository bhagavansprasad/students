#include <stdio.h>
char astrcpy (char *dest , char *src);
char wc (char *ptr );

int main ()
{

	char mac[ ] = " a raja  vari  chepala  cheruvulu  ekkada  unnayo   vethakandi     ";
	char mac2 [100];

	int i, word; 


	i = astrcpy(mac2, mac);
	printf ( "%s\n len = %d\n ", mac2,i);

	word = wc (mac2);
	printf ("No of words : %d\n", word);
}

char astrcpy (char *dest , char *src)
{
	int i = 0;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];     
	}
	dest[i]='\0';
	return i;
}

char wc (char *ptr )
{
	int i;
	int j = 0;
	int p = 0;
	for (i = 0; ptr[i] != '\0'; i++)
	{
		if (ptr[i] == ' ')
		{
			if( p != 0 )
			{
				p = 0;
				j++;
			}
		}
		else
			p ++;
	} 
	if ( p != 0 ) 
		j++;
	return j;
}

