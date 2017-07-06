#include<stdio.h>
main()
{
	char s[10]="rinju";
	s[0]='b';
	printf("%s",s);
//	char *p="bapi";
	char *p=s;
	*p='r';
	while(*p!='\0')
	{
		printf("%c",*p);
		*p++;
	}
}
