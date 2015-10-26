#include <stdio.h>
#include <string.h>
char* astrncat(char *s1,char *s2,int n)
{
	int i,j;
	j=strlen(s1);
	for(i=0;i<n;i++)
	{
		s1[j]=s2[i];
		j++;
	}
	s1[j]='\0';
	return (s1);
}
