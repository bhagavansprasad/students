#include<stdio.h>
main()
{
	char s1[10]="naresh";
	char s2[10]="naresh";
	int t;
	t=astrcmp(s2,s1);
	if(t==1)
	printf("same\n");
	else
		printf("not same\n");
}
int astrcmp(char *s2, char *s1)
{
	int i=0,t;
	for(i=0;s1[i]==s2[i];i++)
	{
if(s1[i]=='\0')
		return 1;
	}
	return 0;
}
