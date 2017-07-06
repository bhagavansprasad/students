#include "stdio.h"

int astrcpy(char *d, char *s)
{
	int i = 0;

	/*
	for (i = 0; s[i] ; i++)
	{
		printf("%c", s[i]);
	}
	*/

	for (i = 0; (d[i] = s[i]) ; i++);

	return i;
}
