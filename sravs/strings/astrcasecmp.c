#include<stdio.h>
#include <string.h>
#include <stdlib.h>
	

int astrtolower(char str1[])
{
	int i=0;
	for(i=0;str1[i]!='\0';i++)
	{
		if(str1[i]>=65 && str1[i]<=91)
		str1[i]=str1[i]+32;
	}	
	printf("string is %s\n",str1);
}

int astrcasecmp(char str1[],char str2[])
{
	int i=0,count=0;
	for(i=0;str1[i]!='\0';i++)
	{
		if(str1[i]!=str2[i])
			count++;
	}
	return count;
}









