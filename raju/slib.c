#include<stdio.h>


main()
{
	char s1[]="MY NAME IS ARUN";
	char s2[]="My name is Arun";
	char s3[100];
	int t;
	
	printf("s1:%s\n",s1);
	printf("s2:%s\n",s2);
	t=astrcmp(s1,s2);

	if(t==0)
	{
		printf("s1 and s2 Strings are equal through strings\n");
	}
	else
	{	
		printf("s1 and s2 Strings are not equal through strings\n");
	}
	
	astrcpy(s3,s1);

	printf("s3:%s\n",s3);
	
/*	t=astrcasecmp(s1,s2);

	if(t==0)
	{
		printf("s1 and s2 Strings are equal through string case comparison\n");
	}
	else
	{	
		printf("s1 and s2 Strings are not equal through string case comparison\n");
	}*/
}	
	



