#include <stdio.h>
char astr_toggle(char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>64&&s[i]<92)
		s[i]=s[i]+32;
		else if(s[i]>96&&s[i]<124)
		s[i]=s[i]-32;
		else
		s[i]=s[i];
	}
	return 0;
}
