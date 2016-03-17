#include<stdio.h>
#include<string.h>
#include<stddef.h>
char* astrcpy( char str3[],char str2[])
{
	int i;
	for(i=0; str2[i]!='\0';i++)
	{
		str3[i]=str2[i];
	}	
		str3[i]='\0';
	return str3;
}


