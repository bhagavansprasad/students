#include<stdio.h>
int i,t;
main()
{
	char s1[25]="mateen";
	char s2[25]="manasa";
	t=astrcmp(s1,s2);
	if(t==0)
	printf("both r same\n");
	else 
	printf("both r different\n");
}
int astrcmp(char*s1,char*s2)
{
	for(i=0;s1[i]!='\0';i++)
	{
		if(s2[i]!=s1[i])
		break;
	}
	if(s1[i]='\0')
	return 0;
	else 
	return 1;
}
