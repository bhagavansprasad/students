#include<stdio.h>
int aatoi(char a)
{
	int i=0,A=48,k;
	for(i=0;A<=57;i++,A++)
	{
		if(a==A)
		{
			return i;
		}
	}
}
