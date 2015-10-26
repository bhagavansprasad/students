#include<stdio.h>
#include<string.h>
int astrcasecmp(char*a,char*b)
{
	int i=0;
	for(;a[i]!='\0'||b[i]!='\0';i++)
	{
		if((atoupper(a[i]))!=(atoupper(b[i])))
		{
			return 0;
		}
	}
	return 1;
}
