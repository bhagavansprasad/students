#include <stdio.h>
char astrncpy (char *dest , char *src, int n );
char wc (char *ptr );
main()
{
	int retval, word; 
	char mac[ ] = "a raja vari chepala cheruvulu ekkada unnayo vethakandi   ";
	char mac2 [100];


	retval = astrncpy (mac2, mac, 30);
	printf ("--> string : %s\n --> length of string : %d\n ", mac2,retval);

	word = wc (mac2);
	printf ("--> No of words : %d\n", word);
}
char astrncpy (char *dest , char *src, int n)
{
	int i = 0;
	for (i = 0; src[i] != '\0' && i < n; i++)
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
	int flag = 0;
	for (i = 0; ptr[i] != '\0'; i++)
	{
		if (ptr[i] == ' ')
		{
			if( flag != 0 )
			{
				flag = 0; 
				j++;
			}
		}
		else
			flag += 1;
	} 
	if ( flag != 0 ) j++;
	return j;
}
