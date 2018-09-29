#include<stdio.h>
#include<string.h>
char *astrncat(char *str1,char *str2,int n)
{
	int i;
	while(*str1!='\0')
		str1++;
	for(i=0;i<n;i++)
	{
		*str1=*str2;
		str1++;
		str2++;
	}
	*str1='\0';
	return str1;
}
main()
{
	char str1[20]="salma";
	char str2[]="mateen1234";
	printf("s1 string before concat:%s\n",str1);
	printf("s2 string before concat:%s\n",str2);
	astrncat(str1,str2,6);
	printf("after string concat:%s\n",str1);
}
