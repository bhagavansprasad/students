#include<stdio.h>
main()
{
	char t;
	char s1[20]="  naresh reddy";
	char s2[20];
	t=astrcpy(s2,s1);
	printf("%s\n",s2);
	return 0;
}
int astrcpy(char *s2,char *s1)
{
	int i=0,t;
	for(i=0;s1[i]!='\0';i++)
	{
		s2[i]=s1[i];
	}
	return t;
}
