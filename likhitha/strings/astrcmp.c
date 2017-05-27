#include <stdio.h>
int astrcmp(char *s1,char *s2)
{
	int i;
	for(i=0 ; s1[i]!='\0'  ;i++)
	{
		if(s1[i]!=s2[i])
			break;
	}
	if(s1[i]==s2[i])
		return 0;
	else
		return 1;
}
