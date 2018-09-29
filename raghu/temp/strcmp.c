#include <stdio.h>
int str_cmp(char *s1,char *s2)
{
	int i, c;
	for(i=0;s1[i]!='\0';i++);
	{
	if(s1[i]==s2[i])
	{
	c++;	
	return 1;
	}
	else
	return 0;
	}
}
