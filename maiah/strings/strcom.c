#include <stdio.h>
main()
{
	int t;
	char s1[20]="venkatesamaiah",s2[20]="veNKATESAMAIAH";
	t=astrcmp(s1,s2);
	if(t==0)
	printf("same\n");
	else
	printf("not same\n");
}
int astrcmp(char *s1,char *s2)
{
	int i=0;
	while(*s1==*s2)
	{
	if(*s1=='\0')
	return 0;
	s1++;
	s2++;
	}
	return 1;
}
