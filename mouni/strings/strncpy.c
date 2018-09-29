#include "stdio.h"

char *astrncpy(char *dest, char *src)
{
	int i, n=5;
	for(i=0; i<5 && src[i]!='\0';i++)
	{
		dest[i]=src[i];
	}
	dest[i]='\0';
	return dest;
}
main()
{
	char s[10]="mounika";
	char s1[10];
	char *d = s1;
	d=astrncpy(s1, s);
	printf("%s\n", d);
}

