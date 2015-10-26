#include <stdio.h>
main()
{
	char s1[100] = "MY CURRent ciTY IS BANGALORE";
	char s2[100] = "my current city is bangalore";
	int t = 0;
	printf ("Before.........\n");
	printf ("%s..%s\n", s1, s2);

	t = strcasecmp(s1, s2);
	if ( t == 0)
		printf ("EQUAL\n");
	else 
		printf ("NOT EQUAL\n");

	printf ("After.........\n");
	printf ("%s..%s\n", s1, s2);
}

int astrcasecmp(char *s1, char *s2)
{
	int i = 0;

#if 0
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] >= 65 && s1[i] <= 90)
		{
			s1[i] =  s1[i] + 32;
		}
	}

	for (i = 0; s2[i] != '\0'; i++)
	{
		if (s2[i] >= 65 && s2[i] <= 90)
		{
			s2[i] = s2[i] + 32;
		}
	}
#endif

	for (i=0; s1[i] == s2[i]; i++)
	{
		if (atoupper(s1[i]) == atoupper(s2[i]))
		{
		}
	}
	return 1;
}

int atoupper(char ch)
{
	//terinary
	return (ch >= 'a' && ch <= 'z' ? ch - 32 : ch);
}
