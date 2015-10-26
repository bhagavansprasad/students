#include <stdio.h>
main ()
{
	int t;
	char s1[100] = "   vinoTH   @ .!!!!com";
	char s2[100];
	int n = 15;
	t = atoupper (s2, s1, n);
	printf ("%s\n", s1);
	printf ("%s\n", s2);
}

int atoupper (char *s2, char *s1, int n)
{
	int i = 0;
	for (i=0; s1[i]!='\0' && i < n; i++)
	{
		if (s1[i] >= 97 && s1[i] <= 122)
		{
			s2[i] = s1[i] - 32;
		}
		else 
		{
			s2[i] = s1[i];
		}
	}
	s2[i] = '\0';
}
