#include <stdio.h>
char* astrcpy (char *d,const char *s1)
{
	int i;

	for(i=0;s1[i]!='\0';i++)
	{
		d[i]=s1[i];
	}
	d[i]='\0';
	return (d);
}

