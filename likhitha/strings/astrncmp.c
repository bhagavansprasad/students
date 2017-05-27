#include <stdio.h>
int astrncmp(char *s1,char *s2 , int n)
{
	int i;
	for(i=0 ; s1[i]!='\0' && i<n  ;i++)
	{
		if(s1[i]!=s2[i])
			break;
	}
	if(s1[i]==s2[i])
		return 0;
	else
		return 1;
}
