#include<stdio.h>

int astrcmp(char *s1,char *s2);
int astrcpy(char *s1,char *s2);

main()
{
	char s1[]="I am Vinoth";
	char s2[]="I am Vinoth";
	char s3[100];
	int t;

	t=astrcmp(s1,s2);

	if(t==0)
	{
		printf("Strings Are equal\n");
	}
	else
	{
		printf("Strings are not equal\n");
	}

	astrcpy(s1,s3);

	printf("S3:%s\n",s3);
}	



