#include<stdio.h>
#include<string.h>
#include<stddef.h>
int astrncmp( char str1[], char str2[],int n)
{
	int i,count=0;
	for(i=0;i<=n && str1[i]!='\0';i++)
	{
		if((str1[i]!=str2[i]))
			count++;
	}
	return count;
}
