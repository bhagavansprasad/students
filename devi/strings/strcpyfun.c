#include <stdio.h>
#include <string.h>
void astrcpy(char *str,char *str1,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		str1[i]=str[i];
	}
	str1[i]='\0';
}
main()
{
	char str[] = "Hai";
	char str1[30];
	astrcpy(str,str1,strlen(str));
	printf("%s str\n",str);
	printf("%s str1\n",str1);
}

