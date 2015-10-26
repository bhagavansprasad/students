#include<stdio.h>
#include<string.h>
int astrcasecmp(char*a,char*b,int n)
{
	int i=0;
	for(;i<n;i++)
	{
		if((toupper(a[i]))!=(toupper(b[i])))
		{
			return 0;
		}
	}
	return 1;
}
