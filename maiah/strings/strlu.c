#include <stdio.h>
char* astrcpy(char *s2,char *s1);
main()
{
	char s1[25]="baNGLoRE",s2[25];
	char *t=astrcpy(s2,s1);
	printf("%s\n",s2);
}
char* astrcpy(char *s2,char *s1)
{
	while(*s1!='\0')
	{
		if(*s1>='A' && *s1<='Z')
		{
			*s1=*s1+'a'-'A';
			*s2=*s1;
		//	return s2;
		}
		else if(*s1>='a' && *s1<='z')
		{
			*s1=*s1-('a'-'A');
			*s2=*s1;
		//	return s2;
		}
		s1++;
		s2++;
	}
	*s2 = '\0';
}

