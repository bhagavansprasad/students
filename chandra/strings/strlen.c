#include <stdio.h>
#include <string.h>
main()
{
	int len;
	char str[] = "balachandra";
	len = strlen(str);
	printf("str : %s\n len is : %d\n", str, len);
}
int get_len(char *pname)
{
	int i;
	for(i=0;pname[i]!='\0';i++)
	//	printf("the length of string:%d",i);
	return i;
}
int pstrlen(char *a)
{
	int len=0;
	while(*a++!='\0')
	{
		len++;
	}
	return len;
}

