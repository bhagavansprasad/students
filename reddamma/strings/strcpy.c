#include<stdio.h>
main()
{
	int t;
	char s1[100]="Aura Networks In Bangalore";
	char s2[30];
	t=astrcpy(s1,s2);
		printf("%s\n",s2);
}
int astrcpy(char *str1,char *str2)
{
	int i;
	for(i=0;str1[i]!='\0';i++)
	{
		str2[i]=str1[i];
	}
	str2[i]='\0';
	return;
}

