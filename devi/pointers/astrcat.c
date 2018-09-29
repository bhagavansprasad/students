#include <stdio.h>
void astrcat(char *s,char *s1,int n,int k)
{
	int i=0,j;
	char str3[30];
	while(*s!='\0')
	{
		str3[i] = *s;
		i++;
		s++;
	}
	//str3[i]='\0';
	while(*s1!='\0')
	{
		str3[i]=*s1;
		i++;
		s1++;
	}
	str3[i]='\0';
	printf("%s %d\n",str3,strlen(str3));
}
main()
{
	char str[]="string";
	char str1[]="concat";
	//char *p,*cp;
	int n = strlen(str),k=strlen(str1);
	astrcat(&str,&str1,n,k);
}
