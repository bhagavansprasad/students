#include<stdio.h>
char *astrcpy(char*,char*);
main()
{
	char str2[20]="SALMA MATEEN";
	char str1[20];
	astrcpy(str1,str2);
	printf("copied string through pointer :%s\n",str1);
}
char *astrcpy(char *p,char *q)
{
	while(*p=*q)
	{
		p++;
		q++;
	}
	return p;
}
