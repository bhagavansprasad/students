#include <stdio.h>
main()
{
	char s[100] = "aura networks";
	int t = 0;
	t = astrlen(s);
	printf ("%d\n", t);
}

int astrlen(char *s)
{
	int i = 0;
	for (i=0; s[i]!='\0'; i++);
	return i; 
}


