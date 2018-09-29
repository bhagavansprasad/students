#include<stdio.h>
main()
{
	char s1[23]="haritha btect";
	int length=0;
	length=astrlen(s1);
		printf("%d",length);
}
int astrlen(char*s)
{
	int i;
	for(i=0;s[i]!='\0';i++);
//	{
//		printf("%d",i);
//	}
	return i;
}

