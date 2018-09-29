#include <stdio.h>
#include <string.h>
char astr_upper(char *s)
{
	int i,j;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>=97&&s[i]<=123)
			s[i]=s[i]-32;
		else
			s[i]=s[i];
	}
	return 0;
}
