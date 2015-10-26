#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char *temp;
	char *str1="paidi";
	char *str2="kumar";
	char *str3;
	str3 = malloc(10);
	temp = str3;

	while(*str1)
	{
		*str3++ = *str1++;
	}
	while(*str2)
	{
		*str3++ = *str2++;
	}
	*str3 = '\0';
	printf("strcat-->=%s\n",temp);
	return 0;
}
