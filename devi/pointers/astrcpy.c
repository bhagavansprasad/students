#include <stdio.h>
void astrcpy(char *p,int n)
{
	char strr[30];
	int i=0;
	while(*p!='\0')
	{
	strr[i]=*p;
	i++;
	p++;
	}
	strr[i]='\0';
	printf("%s",strr);
}
main()
{
	char str[]="string";
	int n = strlen(str);
	///char *p = str;
	astrcpy(&str,n);
}
