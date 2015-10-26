#include"stdio.h"
int rstrlen(const char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++);
	return i;
}

int rstrcmp(const char *s1,const char *s2)
{
	int i;
	for(i=0;s1[i]!='\0';i++)
	{
		if(*s1==*s2)
		{
			s1++,s2++;
		}
		else 
			return *s1-*s2;
	}
	return *s1-*s2;
}
char *rstrcpy(char *dest,const char *src)
{
int i,l;
l=rstrlen(src);
for(i=0;i<l;i++)
{
dest[i]=src[i];
return dest;
}
}
