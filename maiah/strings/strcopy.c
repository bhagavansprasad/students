#include <stdio.h>
char* astrcpy(char *s2,char *s1)
{
	while(*s1!='\0')
	{
	*s2=*s1;
	s1++;
	s2++;
	}
	return s2;
}

main()
{
	char s1[250]="venkatesamaiah and sirisha",s2[250];
	char *t=astrcpy(s2,s1);
	printf("%s\n",s2);
}
