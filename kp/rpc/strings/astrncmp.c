#include<stdio.h>
#include<string.h>
int astrncmp(char*a,char*b,int*n)
{
	int i=0;
	for(;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			return 0;
		}
	}
	return 1;
}
