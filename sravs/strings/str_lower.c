#include<stdio.h>
#include <string.h>
	char* astr_tolower(char str[]);
main()
{
	char buff[20]="aurA neTwWOrks";
	astr_tolower(buff);
	printf("%s \n",buff);
}
char* astr_tolower(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>=65 && str[i]<=91)
			str[i]=str[i]+32;
	}
	str[i]='\0';
	return str;
}

