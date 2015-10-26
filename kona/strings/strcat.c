#include<stdio.h>
#include <string.h>
main()
{
	int i,j;//n=3;
	char s1[15]="Hello";
	char s2[10]="World";
/*	strcat(s1,s2);
	printf("%s\n",s1);*/
	
	for(i=strlen(s1),j=0; /*j<n*/  s2[j]!='\0'; i++,j++)
	{
		s1[i]=s2[j];
	}
		s1[i]='\0';
	printf("%s\n",s1);
}
