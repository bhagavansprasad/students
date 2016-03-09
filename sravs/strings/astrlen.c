#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{

	int i,len=0;;
	char buff[]="aura networks";
	len=astrlen(buff);
	printf("lenth of string:%d\n",len);
}
int astrlen(char str[])
{
	int i=0;
	for(i=0;str[i]!='\0';i++)
	{
	}
	return i;
}
