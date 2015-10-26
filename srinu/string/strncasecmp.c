#include<stdio.h>

#include<string.h>

int astrncasecmp(char *s1,char *s2,int len);

main()

{
	char s1[]="sravani";

	char s2[]="SRAVANI";

	int t,n=20;

	t=astrncasecmp(s1,s2,n);

	printf("t:%d\n",t);

	printf("s1:%s s2:%s\n",s1,s2);

	if(t==0)

	{

		printf("Strings are equal\n");

	}

	else

		printf("Strings are not equal\n");

}

int astrncasecmp(char *s1,char *s2,int len)

{

	int i;

	for(i=0;i<len;i++)

	{

		if(s1[i]>='A' && s1[i]<='Z')

		{

			s1[i]=s1[i]+32;

		}

	}

	for(i=0;i<len;i++)

	{

		if(s2[i]>='A' && s2[i]<='Z')

		{

			s2[i]=s2[i]+32;

		}

	}

	for(i=0;s1[i]==s2[i];i++)

	{

		if(i==len-1)

		{

			return 0;

		}

	}

	return 1;		

}	
