#include<stdio.h>
int astrcpy(char *s2, char *s1);
int astrncpy(char *s2, char *s1, int len);
main()
{
	int i;
	char s1[50]="hema svist kadapa";
	char s2[50];
	char s3[50];

	astrcpy(s2, s1);
	printf("string1:%s\n", s1);
	printf("string2:%s\n", s2);

	astrncpy(s3, s1, 6);
	printf("string1:%s\n", s1);
	printf("string3:%s\n", s3);
}

int astrcpy(char *s2,char *s1)
{
	int i;
	for(i=0;s1[i]!='\0';i++)
	{
		s2[i] = s1[i];
	}

	s2[i]='\0';

	return i;
}

int astrncpy(char *s3, char *s1, int len)
{
	int i;
	for(i=0;i<=len;i++)
	{
		s3[i]=s1[i];
		
	}
	s3[i]='\0';

	return i;
}

