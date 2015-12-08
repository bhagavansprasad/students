#include<stdio.h>
#include<string.h>


int astrncasecmp(char *s1,char *s2,int len)
{
	int i;

	//for(i=0;tolower(s1[i])==tolower(s2[i]);i++);

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (tolower(s1[i]) != tolower(s2[i]))
			return 1;
	}

	return 0;
}	

main()
{
	char s1[]="sravANi";
	char s2[]="sRanvani";
	//char s2[]="SAVANI";
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

