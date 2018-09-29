#include<stdio.h>
#include <string.h>
main()
{
	int t;
	char s1[100]="Aura Networks in bangalore";
	char s2[23];
	t=astrncpy(s1,s2,13);
	printf("%s%s\n",s1,s2);
}
int astrncpy(char *str1,char *str2,int n) 
{
	int i;
	for(i=0;str1[i]!='\0'&&i<=13;i++)
	{
		
		
			str2[i]=str1[i];
		
	}

	str2[i]='\0';
	return;
}

