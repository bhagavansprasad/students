#include <stdio.h>
#include <string.h>
main()
{
	int i;
	char str[] = "balachandra";
	char str1[20];
	astr_cpy(str1,str);
	printf("str1 is : %s\n", str1);
	printf("str is : %s\n", str);
	if(str1[i] == str[i])
	{
		printf("strings are equal\n");
	}
	else
	{
	printf("strings are not equal\n");
	}
}
/*int astr_cpy(char d[],char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
		d[i]=s[i];
	return 0;
}*/

int astr_cpy(char *a,char *b)
{
	while(*a++=*b++);
	*a='\0';
}

