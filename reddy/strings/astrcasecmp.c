#include<stdio.h>
main()
{
char ch1[ ] = "an equalatoral triangle ";
char ch2[ ] = "An Equalatoral Triangle  ";
int c;
        c = astrcasecmp ( ch1 , ch2 );
        if (c)
    printf ("case comparision failed\n"); 
	else 
     printf ("case copmarision success\n" );
}

int astrcasecmp (char *s1, char *s2)
{
  char atoupper(char ch);
  	int i ;
        int c = 0;
	for (i = 0; s1[i] && s2[i]; i++ )
	{
	   c += (atoupper(s1[i]) - atoupper(s2[i]));
	}
	c += (atoupper(s1[i]) - atoupper(s2[i]));
        
        return c;
}

char atoupper(char ch)
{
   int diff = 'a' - 'A';
   if( ch >= 'a' && ch <= 'z')
     ch -= diff;
   return ch;
}
