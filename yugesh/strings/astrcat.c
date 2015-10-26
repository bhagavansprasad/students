#include <stdio.h>
#include <string.h>
void astrcat(char*s2, char*s1)
{
int i,j;
	j=strlen(s2);
	for(i=0;s1[i]!='\0';i++,j++)
	{

		s2[j]=s1[i];
	}
	s2[j]='\0';

}
