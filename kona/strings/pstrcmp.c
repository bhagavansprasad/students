#include<stdio.h>
#include <string.h>
main()
{
	char s1[10]="sreenu";
	char s2[10]="sreenu";
	if(strcmp(s1,s2)==0)
	printf("same\n");
	else
	printf("not same\n");
}
int pstrcmp(char *s1,char *s2)
{ 
	
	while(*s1==*s2)
	{
		s1++;
		s2++;
		if(*s1=='\0')
		return 0;


	}
		return 1;
}
