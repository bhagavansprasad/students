#include <stdio.h>
main()
{
	char s1[] = "IAM COMING FROM TAMILNADU";
	char s2[] = "IAM COMING FROM TAMILNADU";
	int t;
	t = astrcmp (s1,s2);
	if (t == 0)
	{
		printf ("STRINGS ARE EQUAL\n");
	}
	else
	{
		printf ("STRINGS ARE NOT EQUAL\n");
	}
}

int astrcmp (char *s1,char *s2)
{
	int i=0;
	for (i=0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
		{
			return 0;
		}
	}
	return s1[i]-s2[i];
}
