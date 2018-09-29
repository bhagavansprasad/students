#include<stdio.h>
int i;
main()
{
	char s1[25]="haritha btech";
	char s2[25];
	astrcpy(s2,s1);
	printf("s2-->%s\ns1-->%s\n",s2,s1);
	}

int astrcpy(char*s2,char*s1)
{

	for(i=0;s1[i]!='\0';i++)
	{

s2[i]=s1[i];
	
	}
	s2[i]!='\0';

}
