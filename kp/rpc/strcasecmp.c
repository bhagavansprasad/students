#include<stdio.h>
#include<string.h>
int astrcasecmp(char*a,char*b)
{
	int i=0;
	for(;a[i]!='\0';i++)
	{
		if((toupper(a[i]))!=(toupper(b[i])))
		{
			return 0;
			break;
		}
	}
	return 1;
}
