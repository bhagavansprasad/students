#include <stdio.h>
#include <string.h>
char str1[]="paidikumar";
char str2[]="kumar";
int flag;
char strstr1(char *,char * );
main()
{
    char p=strstr1(str1,str2);
	printf("%s\n",p);
}

char strstr1(char *s1,char *s2)
{
	while(*s1)
	{
		if(*s1=='\0')
		{
			flag=0;
			break;
		}
		while(*s2)
		{
			if(*s2==*s1)
			{
				*s1++;
				*s2++;
				flag=1;
			}
			else
			{
				flag=0;
				*s1++;
				break;
			}
		}
	}
	if(flag=1)
		return 0;
	else
		return 1;

