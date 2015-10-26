#include<stdio.h>
main()
{
	int len=0;
	char s1[20]="Aura Networks";
	len=astrlen(s1);
	printf("%d\n",len);
}
int astrlen(char *str)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
	}
	return i;
}

