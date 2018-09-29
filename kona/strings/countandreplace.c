#include <stdio.h>
#include <string.h>
int count(char *str,char ch);
void replace(char *str,char ch1,char ch2);
main()
{
	char str[50];
	strcpy(str,"programming in c language");
	printf("%d\n",count(str,'a'));
	replace(str,'a','z');
	puts(str);
}
int count(char *str,char ch)
{
	int cnt=0;
	while(*str++!='\0')
	if(*str==ch)
	cnt++;
	return cnt;
}
void replace(char *str,char ch1,char ch2)
{
	while(*str++!='\0')
	if(*str==ch1)
	*str=ch2;
}
