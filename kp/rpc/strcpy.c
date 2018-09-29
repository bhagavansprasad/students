#include<stdio.h>
#include<string.h>
char astrcpy(char *s1,char *s2)
{
	int i=0;
	for(;s1[i]!='\0';i++)
	{
		s2[i]=s1[i];
	}
	s2[i]='\0';
	printf("%s\n",s2);
	return s2;
}
