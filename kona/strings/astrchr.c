#include <stdio.h>
#include <string.h>
char* astrstr(char* s1,char ch);
main()
{
	char s1[20]="sreenivasulareddy";
	char ch='e';
	char *s3;
	s3=strchr(s1,ch);
	printf("--->s3 val is:%s\n",s3);
}
char* astrchr(char *s1,char ch)
{
	int i,j;
	char s[20];
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]==ch)
		{
			for(j=0;s1[i]!='\0';j++)
			{
				s[j]=s1[i];
				i++;
			}
			s[j]='\0';
			break;
		}
	}
	return s;
}
