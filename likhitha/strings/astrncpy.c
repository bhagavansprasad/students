#include <stdio.h>
int astrncpy(char *d,char *s,int n)
{
	int i;
#if 0
	for(i=0 ; s[i] !='\0' && i < n ;i++)
		d[i]=s[i];

	d[i]='\0';
#endif
	for(i = 0 ; (d[i] = s[i]) !='\0' && i < n ;i++);
	d[i]='\0';

	return i;
}
