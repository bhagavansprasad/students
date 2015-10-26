#include<stdio.h>
#include<string.h>
main()
{
	char i[20]="heLlo";
	char j[20]="hEllo";
	int n=3;
	if(astrncasecmp(i,j,n)==1)
		printf("the string are same\n");
	else
		printf("the strings are not same\n");
}
