#include<stdio.h>
#include<string.h>
main()
{
	int t;
	char s1[100]="red";
	char s2[100]="reddamma";
	t=astrcmp(s1,s2);
	if(t==0)
	{
		printf("strings are same");
	}
	else if(t==1)
	{
		printf("strings are not same");
	}
}
int astrcmp(char *s,char *d)
{
	int i;
	while(s[i]==d[i]&&s[i]!='\0')
	{
	i++;
	}
	if(s[i]=='\0'&&d[i]=='\0')
	{
		return 0;
	}
	else if(s[i]!=d[i])
	{
		return 1;

	}
}	            


