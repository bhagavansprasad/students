#include <stdio.h>
int astrrev (char *s, char *r)
{
	int i,j,k;
	for(i = 0; s[i] != '\0'; i++);
	{
		k = i-1;
	}
	for(j = 0; j <= i-1; j++)
	{
		r[j] = s[k];
		k--;
	}
	return r[j];
}


















