#include<stdio.h>
#include <string.h>
	char* astr_toupper(char str[]);
main()
{
	char buff[20]="aura networks";
	astr_toupper(buff);
	printf("%s \n",buff);
}
char* astr_toupper(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>=97 && str[i]<=123)
			str[i]=str[i]-32;
	}
	str[i]='\0';
	return str;
}

