#include<stdio.h>
#include<string.h>
//#define_GNU_SOURCE
#if 0
int *astrstr(char *s,char *d)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='n')
		{
		if(s[i+1]=='e')
		{
		if(s[i+2]=='t')
		break;
		}
		}
	}
	return (i);
}
#endif
char * astrstr(char *s,char * d)
{
	int i=0;
	for(i=0;s[i]!='\0'&&d[i]!='\0';i++)
	{
		if(s[i]==d[i])
			printf("%c",d[i]);

	}
	printf("%s\n",d);
}
int main()
{
    int t;
	char s1[]="aura networks";
	char s2[]="bng";
	astrstr(s1,s2);
}



