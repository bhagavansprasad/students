#include <stdio.h>
#include <string.h>
main()
{
	int t = 0;
	char s[100] = " iam         312344 vinoth";
	t = wordcount (s);
	printf ("%d\n", t);
}

int wordcount (char *s)
{
	int i = 0, w = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		while (s[i]==' ')
			i++;
		if (s[i]!=' ' && s[i]!='\0')
			w++;
		while (s[i]!=' ' && s[i]!='\0')
			i++;
	}
	return w;
}
