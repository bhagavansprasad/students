#include <stdio.h>
main()
{
	char s1[100] = "iam coming from bangalore";
	char s2[100];
	int n= 5;
	astrncpy(s2, s1, n);
	printf ("%s\n", s2);
}

int astrncpy(char *s2, char *s1, int n)
{
	int i = 0;
	for (i=0; s1[i]!='\0' && i < n; i++)
	{
		s2[i] = s1[i];
	}
	s2[i] = '\0';
}
