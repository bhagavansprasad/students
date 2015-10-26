#include <stdio.h>
main ()
{
	char man[ ] = "Do   what    you           want   to do...!";
	int i, p;
        man[-1] = 'a' ;
        printf (" String is : " );
        for ( i = 0; man[i] != 0; i++ )
	printf ("%c", man[i]);
        p = wc (man);
	printf ("\n--> No of words : %d\n", p );

}
int wc (char *ptr )
{
	int i;
	int j = 0;
	for ( i = 0; ptr[i] != '\0'; i++ )
	{
      if ((ptr[i] == ' ' && ptr[i-1] !=' ' )||( ptr[i]!=' '&& ptr [i+1] =='\0'))
			j += 1;
	}
	return j;
}

