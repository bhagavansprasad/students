#include <stdio.h>
int astrncpy(char *d,char *s,int n)
{
	int i;
	for(i=0 ; i<n ; i++)
	{
		d[i]=s[i];
	}
	d[i]='\0';
	return i;
}

