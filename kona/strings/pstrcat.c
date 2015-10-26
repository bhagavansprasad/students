#include <stdio.h>
#include <string.h>
main()
{
	char s1[10]="hello";
	char s2[10]="world";
	strcat(s1,s2);
	printf("--->s1 string is :%s\n",s1);
}
char *pstrcat(char *s1,char *s2)
{
	char *p=s1;
	while(*p!='\0')
		p++;
	while(*p++=*s2)
		return s1;
}
