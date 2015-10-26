#include<stdio.h>
#include<string.h>
int astrncpy(char *d,char *s,int len);

main()
{
	char s1[]="Hi Hello How are you";
	char s2[100];
	int n=8;
	printf("s1:%s s2:%s\n",s1,s2);
	astrncpy(s2,s1,n);
	printf("s1:%s s2:%s\n",s1,s2);
}	
int astrncpy(char *d,char *s,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		d[i]=s[i];
		
	}
}	


