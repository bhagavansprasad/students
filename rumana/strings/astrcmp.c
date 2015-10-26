#include<stdio.h>
#include<string.h>
int astrcmp(char str1[],char str2[]);
main()
{
	char str1[20],str2[20];
	int a;
	printf("enter string one");
	gets(str1);
	printf("enter string two");
	gets(str2);

	a=astrcmp(str1,str2);

	if (a==0)

		printf("string is same and a is%d\n",a);
	else if (a<0)

		printf("s1 is lessthan s2 and a is  %d\n",a);
	else

		printf("s1 is greaterthan s2 and a is %d\n",a);
}

int astrcmp(char str1[],char str2[])
{
	int i=0;
	while( str1[i] == str2[i])
	{
		i++;
		if(str1[i] == '\0')
			return 0;;
	}
	return str1[i]-str2[i];
}
