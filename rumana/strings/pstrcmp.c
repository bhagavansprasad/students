#include<stdio.h>
#include <string.h>
main()
{    
    int a;
	char str1[20],str2[20];
	printf("enter first string\n");
	gets(str1);
	printf("enter second string\n");
	gets(str2);
	a=astrcmp(str1,str2);
	if(a==0)
		printf("string is same and a is %d\n",a);
	else if(a<0)
		printf("s1 is lessthan s2 and a is %d\n",a);
	else
		printf("s1 is greater than s2 and a is %d\n",a);
}

int astrcmp(char *p1,char *p2)
{
	while(*p1==*p2)
	{
		p1++;
		p2++;
		if(*p1=='\0')
			return 0;
	}
	return *p1-*p2;
}
