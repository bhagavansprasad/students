#include <stdio.h>
main ()
{
	char s1[100] = "I NEED JOB ONLY";
	char s2[100] = "I NEED JOB";
	int n = 8, t;
	t = astrncmp (s1, s2, n);
	if (t == 0)
	{
		printf ("strings are equal\n");
	}
	else
	{
		printf ("strings are not equal\n");
	}
}

int astrncmp (char *s1, char *s2, int n)
{
	int i = 0;
	for (i=0; s2[i] == s1[i]; i++)
	{
		if (i == n-1)
		{
			return 0;
		}
	}
	return 1;
}
