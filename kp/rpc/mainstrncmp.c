#include<stdio.h>
#include<string.h>
main()
{
	char i[20]="hello";
	char j[20]="hello";
	int n=3;
	if(astrncmp(i,j,n)==1)
		printf("the string aresame\n");
	else
		printf("the strings are not same\n");
}
