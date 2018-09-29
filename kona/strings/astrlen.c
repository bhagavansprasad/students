#include<stdio.h>
int astrlen(char *s1)
{
	int i;
	for(i=0; s1[i]!='\0';i++);
	return (i);
}

