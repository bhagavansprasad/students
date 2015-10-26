#include <stdio.h>
#include <string.h>
void astrncat(char*s2, char*s1, int n)
{
	int i,j;
	j=strlen(s2);
	for(i=0;i<n;i++,j++)
	{
		s2[j]=s1[i];
	}
	s2[j]='\0';

}
