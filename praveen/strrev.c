#include <stdio.h>
#include <string.h>
char astr_rev(char *d,char *s)
{
	int l,i;
	for(l=0;s[l]!='\0';l++);
	printf("%d",l);
	for(i=0;s[i]!='\0';i++)
		d[l-i]=s[i];
	return 0;
}
