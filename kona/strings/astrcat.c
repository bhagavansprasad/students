#include <stdio.h>
#include <string.h>
char* astrcat(char *s1,char *s2)
{
	int j,i;
	j=strlen(s1);
	for(i=0;s2[i]!='\0';i++)
	{
		s1[j]=s2[i];
		j++;
	}
	s1[j]='\0';
	return (s1);
}
