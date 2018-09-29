#include<stdio.h>
#include<string.h>
char astrncpy(char *s1,char *s2,int *n)
{
	int i=0;
	for(;i<n;i++)
	{
		s2[i]=s1[i];
	}
	s2[i]='\0';
	printf("%s\n",s2);
	return s2;
}
