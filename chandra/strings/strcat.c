#include <stdio.h>
#include <string.h>
main()
{
	char str[] = "balachandra";
	char str1[] = "regalagadda";
	 strcat(str1, str);
	printf("strcat is : %s\n", str1);
}
int pstrcat(char *a,char *b)
{
int flag=0;
	while(1)
	{
	if(*a=='\0')
	{
	flag=1;
	}
	if(flag==1)
	{
	*a=*b;
	b++;
	if(*b=='\0')
	break;
	}
	a++;
	}
	return 0;
}

