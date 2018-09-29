#include <stdio.h>
#include <string.h>
char astr_low(char *s)
{
	int i,j;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>=65&&s[i]<=91)	
			s[i]=s[i]+32;
		else
			s[i]=s[i];
	}
	return 0;
}
