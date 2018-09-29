#include<stdio.h>
#include<string.h>


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

main()
{
	char s1[]="sRAvani";
	char s2[]="SAVANI";
	//char s2[]="sravani";
	int t, n=100;

	printf("Before strcasecmp...\n");
	printf("s1 :%s\n",s1);
	printf("s2 :%s\n",s2);

	t = strncasecmp(s1, s2, n);

	printf("After strcasecmp...\n");
	printf("s1 :%s\n", s1);
	printf("s2 :%s\n", s2);
	if(t==0)
		printf("EQUAL\n");
	else
		printf("NOT EQUAL\n");

	printf("======================\n");
	printf("Before astrcasecmp...\n");
	printf("s1 :%s\n",s1);
	printf("s2 :%s\n",s2);

	t = astrncasecmp(s1, s2, n);

	printf("After astrcasecmp...\n");
	printf("s1 :%s\n",s1);
	printf("s2 :%s\n",s2);
	if(t==0)
		printf("EQUAL\n");
	else
		printf("NOT EQUAL\n");

}

