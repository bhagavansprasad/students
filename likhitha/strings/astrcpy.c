#include <stdio.h>
int astrcpy(char *d,char *s)
{
	int i;
	for(i=0 ; s[i]!='\0'  ;i++)
	{
		d[i]=s[i];
	}
	d[i]='\0';
	return i;
}
