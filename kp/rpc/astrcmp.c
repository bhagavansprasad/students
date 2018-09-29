#include<stdio.h>
#include<string.h>
int astrcmp(char*a,char*b)
{
	int i=0;
	for(;a[i]!='\0'||b[i]!='\0';i++)
	{
		if(a[i]!=b[i])
		{
			return 0;
		}
	}
	return 1;
}
