#include<stdio.h>

#include<string.h>

int astrcasecmp(char *s1,char *s2);

main()
{
	char s1[]="sravani";

	char s2[]="SRAVANI";

	int t;

	t=astrcasecmp(s1,s2);

	printf("t:%d\n",t);

	printf("s1:%s s2:%s\n",s1,s2);

	if(t==0)

	{

		printf("two Strings are equal\n");

	}
	else

		printf("two Strings are not equal\n");

}

int astrcasecmp(char *s1,char *s2)

{
	int i;

	for(i=0;s1[i]!='\0';i++)

	{

		if(s1[i]>='A' && s1[i]<='Z')

		{

			s1[i]=s1[i]+32;

		}

	}

	for(i=0;s2[i]!='\0';i++)

	{

		if(s2[i]>='A' && s2[i]<='Z')

		{

			s2[i]=s2[i]+32;

		}

	}

	for(i=0;s1[i]==s2[i];i++)

	{

		if(s1[i]=='\0')

		{

			return 0;

		}

	}

	return 1;		

}
