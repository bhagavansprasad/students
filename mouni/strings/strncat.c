#include "stdio.h"

char *astrncat(char *src, char *dest, int n)
{
	int i,j;
	for(i=0; src[i]!='\0'; i++);

	for(j=0; j<n && dest[j]!='\0'; j++)
	{
		src[i]=dest[j];
		i++;
	}
	src[i]='\0';
	return src;
}

main()
{
	char s[20]="aura";
	char d[20]="networks";
	char *p = s;
	p = astrncat(s, d, 4);
	printf("%s\n", p);
}
