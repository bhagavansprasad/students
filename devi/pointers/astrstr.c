#include <stdio.h>
#include <string.h>
void astrstr(char *s,char *s1,int n,int n1);
main()
{
	char str[]="Aura Networks";
	char str1[]="works";
	int n=strlen(str),n1=strlen(str1);
	astrstr(&str,&str1,n,n1);
}

void astrstr(char *s,char *s1,int n,int n1)
{
	int i,k;
	char *ptr;
	char str2[30];
	printf("%s\n", s);
	for(i=0,k=0;*s!='\0';i++)
	{
		while(*s==*s1 && *s!='\0' && *s1!='\0')
		{
		str2[k]=*s1;
		printf("%c %c\n",*s,*s1);
		k++;
		s1++;
		s++;
		}
		str2[k]='\0';
		printf("%c %c\n",*s,*s1);
		s++;
	}
	if(k==n1)
	printf("%s", str2);
}
