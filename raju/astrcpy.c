#include<stdio.h>
/*#include<string.h>
int astrcpy(char d[],char s[]);

main()
{
	char s1[]="Hi Hello How are you";
	char s2[100];
	printf("s1:%s s2:%s\n",s1,s2);
	astrcpy(s2,s1);
	printf("s1:%s s2:%s\n",s1,s2);
}	*/

int astrcpy(char d[],char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		d[i]=s[i];
	}
}	

